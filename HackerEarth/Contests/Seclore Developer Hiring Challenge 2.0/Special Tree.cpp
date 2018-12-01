#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;
const int LGNMAX = 20;

int a[MAXN];
set<int> M[MAXN];
vector<int> graph1[MAXN],graph[MAXN];
bitset<MAXN> visited;
int parent[LGNMAX][MAXN],depth[MAXN];

void dfs(int curr) {
    for (auto a:graph[curr]) {
        depth[a] = depth[curr] + 1;
        dfs(a);
    }
}

int getparent(int u, int k) {
    for (int i = 0; i < LGNMAX; ++i) {
        if (k & 1)
            u = parent[i][u];
        k >>= 1;
    }
    return u;
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) {
        u = getparent(u, depth[u] - depth[v]);
    } else if (depth[v] > depth[u]) {
        v = getparent(v, depth[v] - depth[u]);
    }
    if (u == v)
        return u;
    for (int i = LGNMAX - 1; i >= 0; i--) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

void preprocess(int n){
    for (int i = 1; i < LGNMAX; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (parent[i - 1][j] != -1) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }
    dfs(1);
}

void fn(int src) {
    visited[src] = 1;
    for (auto i : graph1[src]) {
        if (!visited[i]) {
            parent[0][i] = src;
            graph[parent[0][i]].pb(i);
            fn(i);
        }
    }
}


int main() {
    FastIO;
    int n;
    cin >> n;
    memset(parent, -1, sizeof parent);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        M[a[i]].insert(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph1[u].push_back(v);
        graph1[v].push_back(u);
    }

    fn(1);
    preprocess(n);

    int q;
    cin >> q;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            M[a[x]].erase(x);
            a[x] = y;
            M[y].insert(x);
        } else {
            int flag = 0;
            for (auto i:M[y]) {
                if (x == LCA(x, i)) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
}