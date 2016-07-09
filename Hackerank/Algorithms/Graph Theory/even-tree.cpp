#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[101];
bool visited[101]={0};
int children[101];
int res=0;

int dfs(int n,int src=0){
    visited[src]= true;
    children[src]=1;
    for (int i = 0; i < graph[src].size(); ++i) {
        int curr=graph[src][i];
//        cout<<curr;
        if(!visited[curr]){
            children[src]+=dfs(n,curr);
        }
    }
    return children[src];
}

//https://www.hackerrank.com/challenges/even-tree

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin>>x>>y;
        x--;y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int d=dfs(n,0);
    for (int j = 1; j < n; ++j) {
        if(children[j]%2==0)
            res++;
    }
    cout<<res;
    return 0;
}