#include <vector>
#include <iostream>
#include <climits>
using namespace std;

typedef pair<int,int> edge;

const int MAXN=3005;
long dist[MAXN];
int parent[MAXN];

bool BellmanFord(vector<pair<int ,edge> > &edgelist,int n,int src){
    //Follow Wikipedia Pseudocode
    //Step 1:
    for (int i = 0; i <= n; ++i) {
        dist[i]=INT_MAX;
        parent[i]=-1;
    }
    dist[src]=0;
    //Step 2:
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < edgelist.size(); ++j) {
            int u=edgelist[j].second.first;
            int v=edgelist[j].second.second;
            int w=edgelist[j].first;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]){ //Imp to check dist[u]!= Inf
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    //Step 3:
    for (int j = 0; j < edgelist.size(); ++j) {
        int u=edgelist[j].second.first;
        int v=edgelist[j].second.second;
        int w=edgelist[j].first;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]){ //Imp to check dist[u]!= Inf
            cout<<"Graph contains a negative-weight cycle";
            return 0;
        }
    }
    return 1;
}

int main() {
    int n,m,x,y,w;
    cin>>n>>m;
    vector<pair<int,edge> > edgelist;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        x--;y--;
        //Undirected Graph
        edgelist.push_back(pair<int,edge>(w,edge(x,y)));
        edgelist.push_back(pair<int,edge>(w,edge(y,x)));
    }
    int s;
    cin>>s;
    s--;
    //Input can be take same as Dijkstra for testing.
    if(BellmanFord(edgelist,n,s)){
        for (int i = 0; i < n; ++i) {
            cout<<parent[i]<<" ";
        }
    }
    return 0;
}