#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAXN=1000;
int children[MAXN +1];
vector<int> graph[MAXN];

int dfs(int n,int src,bool visited[]){
    visited[src]= true;
    children[src]=1;
    for (int i = 0; i < graph[src].size(); ++i) {
        int curr=graph[src][i];
//        cout<<curr;
        if(!visited[curr]){
            children[src]+=dfs(n,curr,visited);
        }
    }
    return children[src];
}

//https://www.hackerearth.com/problem/algorithm/monks-birthday-treat/

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;b--;
        graph[a].push_back(b);
    }
    int result=INT_MAX;
    for(int i=0;i<n;i++){
        bool visited[MAXN +1]={0};
        result=min(result,dfs(n,i,visited));
    }
    cout<<result;
    return 0;
}