#include <vector>
#include <iostream>
#include <climits>
#include <queue>
using namespace std;

const int v=3000;
vector<pair<int ,int>> graph[v];

void BellmanFord(int n,int m,int src){
    int dist[n+1];
    bool visited[n+1];
    queue<int> q;
    for (int i = 0; i <= n; ++i) {
        dist[i]=INT_MAX;
        visited[i]= false;
    }
    q.push(src);
    dist[src]=0;
    while (!q.empty()){
        int curr=q.front();
        q.pop();
        if(!visited[curr]){
            visited[curr]=true;
            for (int i = 0; i < graph[curr].size(); ++i) {
                int new_dist=dist[curr] + graph[curr][i].second;
                if(dist[graph[curr][i].first] > new_dist){
                    dist[graph[curr][i].first]=new_dist;
                    if(!visited[graph[curr][i].first])
                        q.push(graph[curr][i].first);
                }
            }
        }
    }
    for (int i = 1; i <=n; ++i) {
        cout<<dist[i]<<" ";
    }
}

int main() {
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        //Undirected Graph
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    int s;
    cin>>s;
    //Input can be take same as Dijkstra for testing.
    BellmanFord(n,m,s);
    return 0;
}

