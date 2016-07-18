#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

const int MAXN=10010;
int dist[MAXN];
bool vis[MAXN]={0};

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

//https://www.hackerearth.com/problem/algorithm/mittal-wants-to-go-to-play/

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int ,int>> graph[MAXN];
        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            x--;y--;
            if(x!=y){
                graph[x].push_back(make_pair(y,w));
                graph[y].push_back(make_pair(x,w));
            }
        }
        dijkstra(graph,n,0);
        int q;
        cin>>q;
        while(q--){
            int a,k;
            cin>>a>>k;
            a--;
            cout<<max(0,k-(2*dist[a]))<<endl;
        }
    }
    return 0;
}