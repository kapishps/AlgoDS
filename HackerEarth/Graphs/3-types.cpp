#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> edge;

const int MAXN=1010;
vector<pair<int, edge>> men,women,mst;
int parent[MAXN+1],rnk[MAXN+1];
map<int,int> map1;

void initializeset(int n){
    for(int i=0; i<=n; i++){
        parent[i]=i;
        rnk[i]=1;
    }
}

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    x = findset(x), y = findset(y);
    if (rnk[x] > rnk[y]){
        parent[y]=x;
        rnk[x]+=rnk[y];
    }
    else{
        parent[x]= y;
        rnk[y]+=rnk[x];
    }
}

void Kruskal(vector<pair<int, edge>> &edgelist){
    sort(edgelist.begin(),edgelist.end());
    for (int i = 0; i < edgelist.size(); ++i) {
        int pu= findset(edgelist[i].second.first);
        int pv= findset(edgelist[i].second.second);
        if(pu != pv){
            map1[-edgelist[i].first]++;
            mst.push_back(edgelist[i]);
//            total+=edgelist[i].first;
            unionset(pu,pv);
        }
    }
}

//https://www.hackerearth.com/problem/algorithm/3-types/

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        if(c==3){
            men.push_back(pair<int,edge>(-3,edge(x,y)));
            women.push_back(pair<int,edge>(-3,edge(x,y)));
        }
        else if(c==1)
            men.push_back(pair<int,edge>(-1,edge(x,y)));
        else
            women.push_back(pair<int,edge>(-2,edge(x,y)));
    }
    int ans=0;
    initializeset(n);
    Kruskal(men);
    if(mst.size()!=n-1){
        cout<<"-1";
        return 0;
    }
    ans+=map1[3]+map1[1];
    mst.clear();
    map1.clear();
    initializeset(n);
    Kruskal(women);
    if(mst.size()!=n-1){
        cout<<"-1";
        return 0;
    }
    ans+=map1[2];
    cout<<m-ans;
    return 0;
}