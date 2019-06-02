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
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;
const int LGNMAX = 20;

map<ll,int> map1;            // <prime no.,frequency>
vector<pair<ll,ll>> edgelist[MAXN];
map<ll,int> weight;
bool vis[MAXN];
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
    }
    else if (depth[v] > depth[u]) {
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


void primeFactors(long long n) {
    while (n%2 == 0) {
        map1[2]++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2) {
        while (n%i == 0) {
            map1[i]++;
            n = n/i;
        }
    }
    if (n > 2)
        map1[n]++;
}


int main() {
    FastIO;
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; ++i) {
        cin >> parent[0][i];
        graph[parent[0][i]].pb(i);
    }

    preprocess(n);

    int lastAns = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll u, v, w;
            cin >> u >> v >> w;
            u = ((u + lastAns - 1) % n) + 1;
            v = ((v + lastAns - 1) % n) + 1;

            map1.clear();

            weight[(u * 1e6L) + v] = w;
            primeFactors(w);

            for (auto i: map1) {
                edgelist[i.first].push_back({u, v});
            }
        }
        else {
            int v, p;
            cin >> v >> p;
            v = ((v + lastAns - 1) % (n - 1)) + 2;

            ll sum = 0;

            for (auto i: edgelist[p]) {
                int lca = LCA(i.first, i.second);
                if (LCA(lca, v) == v) {
                    continue;
                }
                else {
                    if (LCA(i.first, v) == v || LCA(i.second, v) == v) {
                        sum += weight[(i.first * 1e6L) + i.second];
                    }
                }
            }

            lastAns = sum;
            cout << sum << "\n";
        }
    }

}