#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

const int v=3001;
int dist[v];
bool vis[v]={0};

//earlier made pq.push(make_pair(src,dist[src]=0)); thus was using this now using greater.
//struct compare{
//    bool operator()(pair<int, int>&p1 ,pair<int, int>&p2){
//        return p1.second>p2.second;
//    }
//};

void dijkstra(vector<pair<int ,int> > graph[],int n,int src){
    for(int i=0;i<v;i++){
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
            for (int i = 0; i < graph[cv].size(); ++i) {
                if(!vis[graph[cv][i].first] && graph[cv][i].second+cw < dist[graph[cv][i].first]) {
                    dist[graph[cv][i].first]=graph[cv][i].second+cw;
                    pq.push(make_pair(dist[graph[cv][i].first],graph[cv][i].first));
                }
            }
        }
    }
}

//https://www.hackerrank.com/challenges/dijkstrashortreach

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
            graph[x].push_back(make_pair(y,r));
            graph[y].push_back(make_pair(x,r));
        }
        int s;
        cin>>s;
        dijkstra(graph,n,s);
        for (int i = 1; i <=n ; ++i) {
            if(dist[i]!=INT_MAX && dist[i]!=0)
                cout<<dist[i]<<" ";
            if(vis[i]==false)
                cout<<"-1"<<" ";
        }
        cout<<endl;
    }
    return 0;
}
