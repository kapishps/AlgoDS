#include <iostream>
#include <vector>
using namespace std;

const int MAXN=100000;
long long banana[MAXN +1],children[MAXN +1];
bool visited[MAXN +1];

long long dfs(int n,int src,vector<int> graph[]){
    visited[src]= true;
    children[src]=banana[src];
    for (int i = 0; i < graph[src].size(); ++i) {
        int curr=graph[src][i];
//        cout<<curr;
        if(!visited[curr]){
            children[src]+=dfs(n,curr,graph);
        }
    }
    return children[src];
}

//https://www.hackerearth.com/problem/algorithm/kingdom-of-monkeys/

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> graph[n];
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=0;i<n;i++){
            cin>>banana[i];
            visited[i]=false;
        }
        long long result=0;
        for(int i=0;i<n;i++){
            if(!visited[i])
                result=max(result,dfs(n,i,graph));
        }
        cout<<result<<endl;
    }
    return 0;
}