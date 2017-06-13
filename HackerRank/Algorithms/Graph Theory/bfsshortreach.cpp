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


void bfs(vector<int> graph[],int dist[],int n,int s){
    bool visited[n+1];
    for(int i=0;i<=n;i++){
        dist[i]=-1;
        visited[i]=0;
    }
    queue<int> qu;
    qu.push(s);
    dist[s]=0;
    while(!qu.empty()){
        int curr=qu.front();
//        visited[curr]=1;
        for(auto it:graph[curr]){
            if(!visited[it]){
                dist[it] = dist[curr]+6;
                visited[it]=1;                  //Imp to place here
                qu.push(it);
            }
        }
        qu.pop();
    }
}

int main() {
    int q;
    cin>>q;
    while(q--){
        int n,m;
        cin>>n>>m;
        vector<int> graph[n+1];
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int s;
        cin>>s;
        int dist[n+1];
        bfs(graph,dist,n,s);
        for(int i=1;i<=n;i++){
            if(i!=s)
                cout<<dist[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
