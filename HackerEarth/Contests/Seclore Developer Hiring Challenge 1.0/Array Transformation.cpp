#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())

const long long inf = 1e18;
const int MOD = 1e9+7;
const int MAXN = 5e3+9;

int a[MAXN],b[MAXN];
bool visited[MAXN];
vector<pii > graph[MAXN];
ll dist[MAXN];

void dijkstra(int n,int s) {
    for (int i = 0; i <= n; i++) {
        dist[i] = inf;
        visited[i] = 0;
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mp(0, s));
    dist[s] = 0;
    while (!pq.empty()) {
        pii parent = pq.top();
        ll pu = parent.second, pw = parent.first;
        pq.pop();
        if(!visited[pu]) {
            visited[pu] = 1;
            for (auto i:graph[pu]) {
                if (!visited[i.second] && dist[i.second] > pw + i.first) {
                    dist[i.second] = pw + i.first;
                    pq.push(mp(dist[i.second], i.second));
                }
            }
        }
    }
}

int main() {
    FastIO;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    cin >> m;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if( a[i] == b[i])
            continue;
        dijkstra(n,a[i]);
        if (dist[b[i]] == inf) {
            cout << -1;
            return 0;
        }
        ans += dist[b[i]];
    }
    cout<<ans;
}