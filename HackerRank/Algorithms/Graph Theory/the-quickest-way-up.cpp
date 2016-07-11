#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int bfs(int graph[106]){
    int visited[106]={0};
    queue<int> q;
    visited[0]=1;
    q.push(0);
    while (!q.empty()){
        int parent=q.front();
        if(parent==99)
            return visited[parent]-1;
        q.pop();
        if(graph[parent]!=0){
            if(visited[graph[parent]]==0) {
                q.push(graph[parent]);
                visited[graph[parent]] = visited[parent];
            }
        }
        else{
            for (int i = 0; i < 6; ++i) {
                if(visited[parent+i+1]==0){
                    q.push(parent+i+1);
                    visited[parent+i+1]=visited[parent]+1;
                }
            }
        }
    }
    return -1;
}

//https://www.hackerrank.com/challenges/the-quickest-way-up

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    for (int i = 0; i < t; ++i) {
        int graph[106]={0};
        int n;
        cin>>n;
        for (int j = 0; j < n; ++j) {
            int a,b;
            cin>>a>>b;
            graph[a-1]=b-1;
        }
        int m;
        cin>>m;
        for (int j = 0; j < m; ++j) {
            int a,b;
            cin>>a>>b;
            graph[a-1]=b-1;
        }
        cout<<bfs(graph)<<endl;
    }
    return 0;
}
