#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//https://www.hackerrank.com/challenges/bfsshortreach/

struct adjlistnode{
    int dest;
    adjlistnode *next;
};

struct adjlist{
    adjlistnode *head;
};

struct Graph{
    int v;
    adjlist *array;
};

adjlistnode *newadjlistnode(int dest){
    adjlistnode *newnode= new adjlistnode;
    newnode->dest=dest;
    newnode->next=NULL;
    return newnode;
}

Graph *creategraph(int v){
    Graph *graph=new Graph;
    graph->v=v;
    graph->array=new adjlist[v];
    for (int i = 0; i < v; ++i) {
        graph->array[i].head=NULL;
    }
    return graph;
}

void addedge(Graph *graph,int src,int dest){
    adjlistnode *node=newadjlistnode(dest);
    node->next=graph->array[src].head;
    graph->array[src].head=node;
    // Since graph is undirected, add an edge from dest to src also
    node=newadjlistnode(src);
    node->next=graph->array[dest].head;
    graph->array[dest].head=node;
}

void bfs(Graph *graph,int v,int start){
    int visited[v];
    for (int i = 0; i < v; ++i)
        visited[i]= -1;
    queue<int> q;
    visited[start]= 0;
    q.push(start);
    while (!q.empty()){
        adjlistnode *current=graph->array[q.front()].head;
        int parent=q.front();
        while(current){
            if(visited[current->dest]==-1) {
                q.push(current->dest);
                visited[current->dest]=visited[parent]+6;
            }
            current = current->next;
        }
        q.pop();
    }
    for(int i=0;i<v;i++){
        if(visited[i]!=0)
            cout<<visited[i]<<" ";
    }
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        Graph *graph=creategraph(n);
        for(int j=0;j<m;j++){
            int a,b;
            cin>>a>>b;
            addedge(graph,a-1,b-1);
        }
        int start;
        cin>>start;
        bfs(graph,n,start-1);
        cout<<endl;
    }
    return 0;
}
