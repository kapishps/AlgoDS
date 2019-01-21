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
const int MAXN = 3e5+9;

vector<ll> graph[MAXN];
vector<pair<ll,ll>> edgelist;


int main() {
    FastIO;
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edgelist.push_back({u, v});
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll ans = (n * (n - 1) * (n - 2)) / 6;
    ll t = 0;
    for (auto i: edgelist) {
        t += (n - graph[i.first].size() - 1);
        t += (n - graph[i.second].size() - 1);
    }
    cout << ans - (t / 2);
    return 0;
}