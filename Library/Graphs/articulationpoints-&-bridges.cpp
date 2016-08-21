#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=10000;
vector<pair<int,int> > graph[MAXN];
vector<bool> articulation_vertex(MAXN, false);
vector<int> dfs_low(MAXN,0),dfs_parent(MAXN,0),dfs_num(MAXN,-1);
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int src){
    dfs_low[src] = dfs_num[src] = dfsNumberCounter++;
    for (int j = 0; j < (int)graph[src].size(); j++) {
        int cv = graph[src][j].first;
        if (dfs_num[cv] == -1) {
            dfs_parent[cv] = src;
            if (src == dfsRoot)                     // special case if u is a root
                rootChildren++;
            articulationPointAndBridge(cv);
            if (dfs_low[cv] >= dfs_num[src])
                articulation_vertex[src] = true;
            if (dfs_low[cv] > dfs_num[src])    //we remove ‘=’ for finding bridges
                cout<<"Edge "<<src<<" "<<cv<<" is a bridge"<<endl;
            dfs_low[src] = min(dfs_low[src], dfs_low[cv]);     // update dfs_low
        }
        else if (cv != dfs_parent[src])        //a back edge and not direct cycle
            dfs_low[src] = min(dfs_low[src], dfs_num[cv]);     // update dfs_low
    }
}

int main() {
    /* 1---0---3
       |  /    |
       | /     4
        2
    Input: 5 5         Output:Edge 3 4 is a bridge
           1 0         Edge 0 3 is a bridge
           0 2         Articulation Points: 0 3
           2 1
           0 3
           3 4  */
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {       //Input can be taken from GFG for testing
        int x,y,w=1;
        cin>>x>>y;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }

    for (int i = 0; i < n; i++){
        if (dfs_num[i] == -1) {
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
            if(rootChildren > 1)                    // special case
                articulation_vertex[dfsRoot] = true;
        }
    }
    cout<<"Articulation Points: ";
    for (int i = 0; i < n; i++) {
        if (articulation_vertex[i]) {
            cout<<i<<" ";
        }
    }
    return 0;
}