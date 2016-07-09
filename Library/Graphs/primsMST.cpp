#include <vector>
#include <iostream>
#include <climits>
#include <queue>
using namespace std;

const int v=3000;
vector<pair<int ,int>> graph[v];

int primsmst(int n,int src){
    int key[n+1],parent[n+1];
    bool visited[n+1];
    struct compare{
        bool operator()(pair<int,int> &p1,pair<int,int> &p2){
            return p1.second>p2.second;
        }
    };
    priority_queue<pair<int ,int>,vector<pair<int,int>>,compare> pq;
    for (int i = 1; i <=n; ++i) {
        key[i]=INT_MAX;
        parent[i]=-1;
        visited[i]= false;
    }
    pq.push(make_pair(src,key[src]=0));
    while (!pq.empty()){
        pair<int,int> curr=pq.top();
        pq.pop();
        int cv=curr.first;
        if(!visited[cv]){
            visited[cv]=true;
            for (int i = 0; i < graph[cv].size(); ++i) {
                if(!visited[graph[cv][i].first] && key[graph[cv][i].first]>graph[cv][i].second){
                    key[graph[cv][i].first]=graph[cv][i].second;
                    parent[graph[cv][i].first]=cv;
                    pq.push(make_pair(graph[cv][i].first,graph[cv][i].second));
                }
            }
        }
    }
    int sum=0;
    for (int i = 1; i <= n; ++i) {
        //cout<<parent[i]<<"-"<<i<<endl;
        sum+=key[i];
    }
    return sum;
}

int main() {
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        //Undirected Graph
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }
    int s;
    cin>>s;
    cout<<primsmst(n,s);
    return 0;
}

