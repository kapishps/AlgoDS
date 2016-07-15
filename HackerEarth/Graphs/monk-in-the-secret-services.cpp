#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

const int v=105;
int dist[v];
bool vis[v]={0};

void dijkstra(vector<pair<int ,int> > graph[],int n,int src){
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        vis[i]=false;
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push(make_pair(dist[src]=0,src));
    while (!pq.empty()){
        pair<int ,int> curr=pq.top();
        pq.pop();
        int cv=curr.second,cw=curr.first;
        if(!vis[cv]){
            vis[cv]= true;
            for (vector<pair<int,int> >::iterator it = graph[cv].begin(); it != graph[cv].end(); it++) {
                if (dist[cv] + it->second < dist[it->first]) {
                    dist[it->first] = dist[cv] + it->second;
                    pq.push(make_pair(dist[it->first], it->first));
                }
            }
        }
    }
}

//https://www.hackerearth.com/code-monk-graph-theory-ii/algorithm/monk-in-the-secret-services/

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int ,int>> graph[3001];
        for(int i=0;i<m;i++){
            int x,y,r;
            cin>>x>>y>>r;
            x--;y--;
            graph[x].push_back(make_pair(y,r));
            graph[y].push_back(make_pair(x,r));
        }
        int s,a,h;
        cin>>s>>a>>h;
        s--;a--;h--;
        int ans[v]={0};
        dijkstra(graph,n,s);
        for (int i = 0; i < n; ++i) {
            ans[i]=dist[i];
        }
        dijkstra(graph,n,a);
        for (int i = 0; i < n; ++i) {
            ans[i]+=2*dist[i];
        }
        dijkstra(graph,n,h);
        int result=0;
        for (int i = 0; i < n; ++i) {
            if(i==a || i==s || i==h)
                continue;
            ans[i]+=dist[i];
            result=max(result,ans[i]);
        }
        cout<<result<<endl;
    }
    return 0;
}