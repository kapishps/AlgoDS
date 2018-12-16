#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

vector<pii> graph[MAXN];
map<pii,int> edgelist;
int parent[MAXN], depth[MAXN], children[MAXN];
bool visited[MAXN];

void dfs(int src){
    visited[src] = true;

    for(auto i:graph[src]){
        if(!visited[i.first]){
            parent[i.first] = src;
            depth[i.first] = 1 + depth[src];
            children[src]++;
            dfs(i.first);
        }
    }
}


// 54/100 score

int main() {
    FastIO;
    int n;
    cin>>n;
    for (int i = 0; i < n - 1; ++i) {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
        edgelist[make_pair(u,v)] = w;
        edgelist[make_pair(v,u)] = w;
    }

    dfs(1);

    int q;
    cin>>q;

    while(q--){
        int x,y,z;
        cin>>x>>y>>z;

        vector<pair<pii,int>> path;

        int a = x,b = y;
        while(depth[a] < depth[b]){
            pii t = make_pair(b,parent[b]);
            path.push_back(make_pair(t,edgelist[t]));
            b = parent[b];
        }

        while(depth[a] > depth[b]){
            pii t = make_pair(a,parent[a]);
            path.push_back(make_pair(t,edgelist[t]));
            a = parent[a];
        }

        while(a != b){
            pii t = make_pair(a,parent[a]);
            path.push_back(make_pair(t,edgelist[t]));
            t = make_pair(b,parent[b]);
            path.push_back(make_pair(t,edgelist[t]));
            a = parent[a];
            b = parent[b];
        }


        int flag = 0;
        for(auto i : path){
            if(i.second > z)
                flag = 1;
        }

        if(flag == 1)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }

    return 0;
}