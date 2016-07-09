#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define edge pair<int,int>

vector<pair<int, edge>> edgelist;
int parent[50001],rnk[50001];
int result=0;

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

void Kruskal(int n){
    sort(edgelist.begin(),edgelist.end());
    for (int i = 0; i < edgelist.size(); ++i) {
        int pu= findset(edgelist[i].second.first);
        int pv= findset(edgelist[i].second.second);
        if(pu != pv){
            result=max(result,edgelist[i].first);
            unionset(pu,pv);
        }
        if(findset(1)==findset(n))
            return;
    }
}

//https://www.hackerrank.com/challenges/jack-goes-to-rapture

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edgelist.push_back(pair<int,edge>(w,edge(x,y)));
    }
    for(int i=0; i<=n; i++){
        parent[i]=i;
        rnk[i]=0;
    }
    Kruskal(n);
    if(findset(n)==findset(1))
        cout<<result;
    else
        cout<<"NO PATH EXISTS";
    return 0;
}
