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
const int MAXN = 1e6+9;

string city[1009];
vector<pii> graph[MAXN];
ll dist[MAXN];
map<int,int> vendors;
bool visited[MAXN];

void dijkstra(int n, int s) {
    for (int i = 0; i <= n; i++) {
        dist[i] = inf;
        visited[i] = 0;
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mp(0, s));
    dist[s] = 0;
    while (!pq.empty()) {
        pii parent = pq.top();
        int pu = parent.second, pw = parent.first;
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

void dfs(int s){
    if(visited[s] || vendors[s] > 0)
        return;
    visited[s] = 1;
    for(auto i: graph[s]){
        dfs(i.second);
    }
}

int main() {
    FastIO;
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    getline(cin, city[0]);      // throwaway
    for (int i = 0; i <= n; ++i) {
        getline(cin, city[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < city[i+1].size(); ++j) {
            if (j % 2 == 1 && city[i+1][j] == ' ') {
                graph[(i * m) + ((j - 1) / 2)].push_back({1, ((i + 1) * m) + ((j - 1) / 2)});
                graph[((i + 1) * m) + ((j - 1) / 2)].push_back({1, (i * m) + ((j - 1) / 2)});
            }
            if (j % 2 == 0 && city[i+1][j] == ' ') {
                graph[(i * m) + ((j - 1) / 2)].push_back({1, (i * m) + (j / 2)});
                graph[(i * m) + (j / 2)].push_back({1, (i * m) + ((j - 1) / 2)});
            }

        }
    }

    int k,u,v;
    cin>>k>>u>>v;
    u--;
    v--;
    int z = (u*m) +v;
    vendors[z]++;
    for (int i = 0; i < k-1; ++i) {
        cin>>u>>v;
        u--;
        v--;
        vendors[(u*m) + v]++;
        graph[z].push_back({0, (u*m) +v});
        graph[(u*m) +v].push_back({0, z});
    }

    dijkstra(n*m, z);
    memset(visited, 0, sizeof(visited));
    dfs(((x-1)*m)+y-1);
    ll ans = 0;
    for(int i=0; i<= n*m;i++){
        if(visited[i])
            ans = max(ans, dist[i]);
    }

    cout<<ans;
    return 0;
}