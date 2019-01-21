#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;
const int LGNMAX = 20;

int parent[LGNMAX][MAXN],depth[MAXN];
int maxval[LGNMAX][MAXN];
vector<pii> graph[MAXN];
bool visited[MAXN];

void dfs(int curr) {
    visited[curr] = 1;
    for (auto a:graph[curr]) {
        if (!visited[a.first]) {
            depth[a.first] = depth[curr] + 1;
            dfs(a.first);
            maxval[0][a.first] = a.second;
            parent[0][a.first] = curr;
        }
    }
}

pii getparent(int u, int k) {
    int maxW = 0;
    for (int i = 0; i < LGNMAX; ++i) {
        if (k & 1) {
            maxW = max(maxW, maxval[i][u]);
            u = parent[i][u];
        }
        k >>= 1;  // k /= 2
    }
    return {u, maxW};
}

pii LCA(int u, int v) {
    int maxW = 0;
    if (depth[u] > depth[v]) {
        tie(u, maxW) = getparent(u, depth[u] - depth[v]);

    } else if (depth[v] > depth[u]) {
        tie(v, maxW) = getparent(v, depth[v] - depth[u]);
    }
    if (u == v)
        return {u, maxW};
    for (int i = LGNMAX - 1; i >= 0; i--) {
        if (parent[i][u] != parent[i][v]) {
            maxW = max(maxW, max(maxval[i][u], maxval[i][v]));
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return {parent[0][u], max(maxW, max(maxval[0][u], maxval[0][v]))};
}

void preprocess(int n) {
    memset(parent, -1, sizeof parent);
    depth[1] = 1;
    dfs(1);

    for (int i = 1; i < LGNMAX; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (parent[i - 1][j] != -1) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
                maxval[i][j] = max(maxval[i - 1][j], maxval[i - 1][parent[i - 1][j]]);
            }
        }
    }
    // dfs(1);
}

// https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/optimal-connectivity-c6ae79ca/

int main() {
    FastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    preprocess(n);

    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int lca, lcaw;
        tie(lca, lcaw) = LCA(x, y);
        if (z >= lcaw)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }

    return 0;
}