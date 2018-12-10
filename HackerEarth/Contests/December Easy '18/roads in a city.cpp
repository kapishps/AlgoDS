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

vector<pii> graph[MAXN];
int dist[1009][1009];
bool vis[MAXN];

void dijkstra(int src){
    for(int i=0;i<1009;i++){
        dist[src][i]=inf;
        vis[i]=false;
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push(make_pair(dist[src][src]=0,src));
    while (!pq.empty()){
        pair<int ,int> curr=pq.top();
        pq.pop();
        int cv=curr.second;
        if(!vis[cv]){
            vis[cv]= true;
            for(auto it : graph[cv]){
                if(dist[src][cv] + it.second < dist[src][it.first]){
                    dist[src][it.first] = dist[src][cv] + it.second;
                    pq.push(make_pair(dist[src][it.first], it.first));
                }
            }
        }
    }
}


// 20/100 solution

int main() {
    FastIO;
    int n;
    cin>>n;
    for (int i = 0; i < n - 1; ++i) {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(make_pair(v,1));
        graph[v].push_back(make_pair(u,1));
    }

    if(n<1001){
        for (int i = 0; i < n; ++i) {
            dijkstra(i);
        }
    }

    vector<int> vertices;
    vector<int> answers;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        x--;
        vertices.push_back(x);
        int ans = inf, vertx = -1;
        for (int j = 0; j < n; ++j) {
            int temp = 0;
            for(auto it: vertices){
                temp = max(dist[j][it],temp);
            }
            if(temp<ans) {
                ans = temp;
                vertx = ++i;
            }
        }
        cout<<vertx<<" ";
    }
    return 0;
}