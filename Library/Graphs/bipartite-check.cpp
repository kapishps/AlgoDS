#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN=10000;
vector<pair<int,int> > graph[MAXN];

bool isbipartite(int n,int src){    //Modified BFS
    queue<int> q;
    vector<int> color(n,-1);  //initialise color of vertex with nocolor.
    color[src]=0;
    q.push(src);
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for(auto a:graph[u]){
            int v=a.first;
            if(color[v]==-1){
                color[v]=1-color[u];    //we just need 2 colors (0,1)
                q.push(v);
            }
            else if(color[v]==color[u])
                return false;
        }
    }
    return true;
}

int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    if(isbipartite(n,0))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}