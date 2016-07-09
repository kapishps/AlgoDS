//
// Created by kapish on 8/6/16.
//

#include <iostream>
#include <queue>

using namespace std;

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

void breadthfirstsearch(Graph *graph,int v,int start){
    bool visited[v];
    for (int i = 0; i < v; ++i)
        visited[i]= false;
    queue<int> q;
    visited[start]= true;
    q.push(start);
    while (!q.empty()){
        adjlistnode *current=graph->array[q.front()].head;
        cout<<q.front()<<" ";
        q.pop();
        while(current){
            if(!visited[current->dest]) {
                q.push(current->dest);
                visited[current->dest]=true;
            }
            current = current->next;
        }
    }
    return;
}

int main() {
    int v=5;
    Graph *graph=creategraph(v);
    addedge(graph,0,1);
    addedge(graph,0,4);
    addedge(graph,1,2);
    addedge(graph,1,3);
    addedge(graph,1,4);
    addedge(graph,2,3);
    addedge(graph,3,4);
    breadthfirstsearch(graph,5,0);
    return 0;
}