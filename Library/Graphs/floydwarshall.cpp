#include <iostream>
#include <climits>
using namespace std;

const int v=401;
long dist[v][v];

void FloydWarshall(int graph[][v],int n){

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j]=graph[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    int graph[n][v];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=INT_MAX;
        }
    }

    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x-1][y-1]=w;
    }
    FloydWarshall(graph,n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(dist[a-1][b-1]==INT_MAX)
            cout<<"-1"<<endl;
        else
            cout<<dist[a-1][b-1]<<endl;
    }
    return 0;
}
