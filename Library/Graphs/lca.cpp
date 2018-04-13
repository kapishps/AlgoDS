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
const int MAXN = 1e5+9;
const int LGNMAX = 20;

int parent[LGNMAX][MAXN],depth[MAXN];
vector<int> graph[MAXN];

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

//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/tree-queries-21
// Binary Raise for Computing LCA

int main() {
    FastIO;
    int n, k;
    cin >> n >> k;

    memset(parent, -1, sizeof parent);

    for (int i = 2; i <= n; ++i) {
        cin >> parent[0][i];
        graph[parent[0][i]].pb(i);
    }

    preprocess(n);

    while(k--) {
        int num;
        cin >> num;
        int result;
        for (int j = 0; j < num; ++j) {
            int temp;
            cin >> temp;
            if (j == 0)
                result = temp;
            else
                result = LCA(result, temp);
        }
        cout << result << "\n";
    }
    return 0;
}