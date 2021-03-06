#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> edge;
const int MAXN=5000;
vector<pair<int, edge> > edgelist;
int parent[MAXN+1],rnk[MAXN+1];
int total=0;

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    x = findset(x), y = findset(y);
    if (rnk[x] > rnk[y])
        parent[y] = x;
    else
        parent[x] = y;
    if (rnk[x] == rnk[y])
        rnk[y]++;
}

void Kruskal(){
    sort(edgelist.begin(),edgelist.end());
    for (int i = 0; i < edgelist.size(); ++i) {
        int pu= findset(edgelist[i].second.first);
        int pv= findset(edgelist[i].second.second);
        if(pu != pv){
//            mst.push_back(edgelist[i]);
            total+=edgelist[i].first;
            unionset(pu,pv);
        }
    }
}

//https://www.hackerearth.com/problem/algorithm/maximum-spanning-tree/

int main() {
    int t;
    cin>>t;
    while (t--){
        int n,m,x,y,w;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y>>w;
            x--;y--;
            w=-w;
            edgelist.push_back(pair<int,edge>(w,edge(x,y)));
        }
        for(int i=0; i<=n; i++){
            parent[i]=i;
            rnk[i]=0;
        }
        total=0;
        Kruskal();
        cout<<-total<<endl;
        edgelist.clear();
    }
    return 0;
}