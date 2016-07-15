#include <vector>
#include <iostream>
#include <climits>
using namespace std;

typedef pair<int,int> edge;

const int MAXN=105;
long dist[MAXN];

bool BellmanFord(vector<pair<int ,edge> > &edgelist,int n,int src){
    for (int i = 0; i <= n; ++i) {
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < edgelist.size(); ++j) {
            int u=edgelist[j].second.first;
            int v=edgelist[j].second.second;
            int w=edgelist[j].first;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) //Imp to check dist[u]!= Inf
                dist[v] = dist[u] + w;
        }
    }
    for (int j = 0; j < edgelist.size(); ++j) {
        int u=edgelist[j].second.first;
        int v=edgelist[j].second.second;
        int w=edgelist[j].first;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]){ //Imp to check dist[u]!= Inf
//            cout<<"Graph contains a negative-weight cycle";
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 1;
}

//https://www.hackerearth.com/problem/algorithm/monks-business-day/

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int ,edge> > edgelist;
        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            x--;y--;
            edgelist.push_back(pair<int,edge>(-w,edge(x,y)));
            //we have to find atleast one positive weight cycle hence
            //use usual BF algo to find negative weight cycle by inverting all weights
        }
        BellmanFord(edgelist,n,0);
    }
    return 0;
}