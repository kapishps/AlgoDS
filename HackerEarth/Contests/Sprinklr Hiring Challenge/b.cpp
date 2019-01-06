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
const int MAXN = 5e5+9;

int k;
bool visited[MAXN];
vector<pii > graph[MAXN];
ll dist[MAXN],ans[MAXN];
priority_queue<int, vector<int>, greater<int>> minHp[MAXN], temp;

void dijkstra(int n,int s) {
    for (int i = 0; i <= n; i++) {
        dist[i] = inf;
        visited[i] = 0;
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        pii parent = pq.top();
        ll pu = parent.second, pw = parent.first;
        pq.pop();
        if (!visited[pu]) {
            visited[pu] = 1;
            for (auto i:graph[pu]) {
                if (!visited[i.second] && dist[i.second] > pw + i.first) {
                    dist[i.second] = pw + i.first;
                    pq.push({dist[i.second], i.second});
                }

                if(!visited[i.second] && minHp[i.second].empty()){
                    minHp[i.second] = minHp[pu];
                    minHp[i.second].push(i.first);
                    if (minHp[i.second].size() > k)
                        minHp[i.second].pop();

                    temp = minHp[i.second];
                    ans[i.second] = dist[i.second];

                    while(!temp.empty()){
                        ans[i.second] -= temp.top();
                        temp.pop();
                    }

                    ans[i.second] = max(0LL, ans[i.second]);
                }

                if(!visited[i.second] && !minHp[i.second].empty()){
                    temp = minHp[pu];
                    temp.push(i.first);
                    if (temp.size() > k)
                        temp.pop();

                    ll curr_ans = dist[pu] + i.first;
                    while(!temp.empty()){
                        curr_ans -= temp.top();
                        temp.pop();
                    }

                    if(curr_ans < ans[i.second]){
                        ans[i.second] = max(0LL,curr_ans);
                        minHp[i.second] = minHp[pu];
                        minHp[i.second].push(i.first);
                        if (minHp[i.second].size() > k)
                            minHp[i.second].pop();
                    }
                }
            }
        }
    }
}


int main() {
    FastIO;
    int n,m;
    cin>>n>>m>>k;
    for (int i = 0; i < m; ++i) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
    }

    dijkstra(n,1);

    for (int i = 1; i <= n; ++i) {
        cout<<ans[i]<<" ";
    }

    return 0;
}

//4 4 1
//1 2 2
//2 3 3
//1 3 6
//3 4 11