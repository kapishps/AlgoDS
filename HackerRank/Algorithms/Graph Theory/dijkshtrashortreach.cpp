#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

//earlier made pq.push(make_pair(src,dist[src]=0)); thus was using this now using greater.
//struct compare{
//    bool operator()(pair<int, int>&p1 ,pair<int, int>&p2){
//        return p1.second>p2.second;
//    }
//};

void dijkstra(vector<pii> graph[],ll dist[],bool visited[],int n,int s) {
    for (int i = 0; i <= n; i++) {
        dist[i] = inf;
        visited[i] = 0;
    }
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mp(0, s));
    dist[s] = 0;
    while (!pq.empty()) {
        pii parent = pq.top();
        int pu = parent.second, pw = parent.first;
        pq.pop();
        if(!visited[pu]) {
            visited[pu] = 1;
            for (auto i:graph[pu]) {
                if (!visited[i.second] && dist[i.second] > pw + i.first) {
                    dist[i.second] = pw + i.first;
                    pq.push(mp(dist[i.second], i.second));
                }
            }
        }
    }
}

int main() {
    Boost;
    int q;
    cin>>q;
    while(q--){
        int n,m;
        cin>>n>>m;
        vector<pii> graph[n+1];
        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            graph[x].push_back(mp(w,y));
            graph[y].push_back(mp(w,x));
        }
        int s;
        cin>>s;
        ll dist[n+1];
        bool visited[n + 1];
        dijkstra(graph,dist,visited,n,s);
        for (int i = 1; i <=n ; ++i) {
            if(visited[i]==false)
                cout<<"-1"<<" ";
            else if(i!=s)
                cout<<dist[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
