#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAXN=1000010;
vector<pair<int ,int>> graph[MAXN];
unordered_map<int,long long > map1;

long long dfs(int src){
    long long result=0;
    for(auto a:graph[src]){
        if(map1[a.first]>0)
            result=max(result,2+map1[a.first]+a.second);
        else
            result=max(result,2+dfs(a.first)+a.second);
    }
    map1[src]=result;
    return result;
}

//https://www.hackerearth.com/problem/algorithm/childfree-time-1/

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        graph[x].push_back(make_pair(y,w));
    }
    long long ans=0;
    for (int i=0;i < n;i++){
        ans=max(ans,dfs(i));
    }
    cout<<ans;
    return 0;
}