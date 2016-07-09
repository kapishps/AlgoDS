// Created by kapish on 17/6/16.
//
//Implementation for Dijkstra's SSSP(Single source shortest path) algorithm
//This is an optimized algorithm running in O(E*log(V))

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
#define INF INT_MAX //Infinity

const int sz=3001; //Maximum possible number of vertices. Preallocating space for DataStructures accordingly
vector <pair<int,int> > graph[sz]; //Adjacency list
int dis[sz]; //Stores shortest distance
bool vis[sz]={0}; //Determines whether the node has been visited or not

void Dijkstra(int source, int n) //Algorithm for SSSP
{
    for(int i=0;i<sz;i++) //Set initial distances to Infinity
        dis[i]=INF;
    //Custom Comparator for Determining priority for priority queue (shortest edge comes first)
    class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){return p1.second>p2.second;}};
    priority_queue<pair<int,int> ,vector<pair<int,int> >, prioritize> pq; //Priority queue to store vertex,weight pairs
    pq.push(make_pair(source,dis[source]=0)); //Pushing the source with distance from itself as 0
    while(!pq.empty())
    {
        pair<int, int> curr=pq.top(); //Current vertex. The shortest distance for this has been found
        pq.pop();
        int cv=curr.first,cw=curr.second; //'cw' the final shortest distance for this vertex
        if(vis[cv]) //If the vertex is already visited, no point in exploring adjacent vertices
            continue;
        vis[cv]=true;
        for(int i=0;i<graph[cv].size();i++) //Iterating through all adjacent vertices
            if(!vis[graph[cv][i].first] && graph[cv][i].second+cw<dis[graph[cv][i].first]) //If this node is not visited and the current parent node distance+distance from there to this node is shorted than the initial distace set to this node, update it
                pq.push(make_pair(graph[cv][i].first,(dis[graph[cv][i].first]=graph[cv][i].second+cw))); //Set the new distance and add to priority queue
    }
}

int main() {
    int n,m,x,y,w;//Number of vertices and edges
    //cout<<"Enter number of vertices and edges in the graph\n";
    cin>>n>>m;
    for(int i=0;i<m;i++) //Building Graph
    {
        cin>>x>>y>>w; //Vertex1, Vertex2, weight of edge
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    //cout<<"Enter source for Dijkstra's SSSP algorithm\n";
    int source;
    cin>>source;
    Dijkstra(source,n);//SSSP from source (Also passing number of vertices as parameter)
    cout<<"Source is: "<<source<<". The shortest distance to every other vertex from here is: \n";
    for(int i=1;i<=n;i++)//Printing final shortest distances from source
    {
        cout<<"Vertex: "<<i<<" , Distance: ";
        dis[i]!=INF? cout<<dis[i]<<"\n" : cout<<"-1\n";
    }
    return 0;
}
