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
const int MAXN = 2e6+9;

vector<pair<long, long>> graph[MAXN];
ll dist[MAXN];
bool visited[MAXN];

void dijkstra(int s) {
    for (int i = 0; i <= MAXN; i++) {
        dist[i] = inf*1000LL;
        visited[i] = 0;
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
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
    ll n,m,k;
    cin>>n>>m>>k;
    for (int i = 0; i < m; ++i) {
        ll u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        for(int j = 0; j <= k; j++){
            graph[(j*n) + u].push_back({w,(j*n) + v});
            graph[(j*n) + v].push_back({w,(j*n) + u});
        }
        for(int j = 1; j <= k; j++){
            graph[(j*n) + u].push_back({0,((j-1)*n) + v});
            graph[(j*n) + v].push_back({0,((j-1)*n) + u});
        }
    }

    for(int j = 1; j <= k; j++){
        graph[(j*n)].push_back({0,0});
        graph[0].push_back({0,(j*n)});
    }

    dijkstra(k*n); 
    for (int i = 0; i < n; ++i) {
        cout<<dist[i]<<" ";
    }
}