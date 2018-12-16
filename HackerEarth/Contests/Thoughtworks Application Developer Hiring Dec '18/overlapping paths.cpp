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
const int MAXN = 5e5+9;

vector<int> graph[MAXN];
bool visited[MAXN];
int parent[MAXN];
set<int> path;

vector<int> x,y;

void dfs1(int src, int x){
    visited[src] = 1;

    for(auto i: graph[src]){
        if(!visited[i]){
            dfs1(i,src);
            parent[i] = src;
        }
    }
}

void dfs2(int src){
    visited[src] = 1;
    if(present(path,src))
        return;
    for(auto i : graph[src]){
        if(!visited[i])
            dfs2(i);
    }
    x.push_back(src);
}

void dfs3(int src){
    visited[src] = 1;
    if(present(path,src))
        return;
    for(auto i: graph[src]){
        if(!visited[i])
            dfs3(i);
    }
    y.push_back(src);
}

int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        x.clear();
        y.clear();
        path.clear();
        for(int i=0;i<=n ;i++){
            graph[i].clear();
            visited[i] = 0;
            parent[i] = 0;
        }

        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int u,v;
        cin>>u>>v;

        dfs1(u,v);

        int z = v;

        while(z != u){
            path.insert(z);
            z = parent[z];
        }


        for(int i =0 ;i<=n; i++){
            visited[i] = 0;
        }
        path.insert(v);
        path.erase(u);
        dfs2(u);

        for(int i=0;i<=n;i++){
            visited[i] =0;
        }
        path.insert(u);
        path.erase(v);
        dfs3(v);

        x.push_back(u);
        y.push_back(v);
        int ans = 0;
        for(auto i:x){
            for(auto j:y){
                ans = max(ans,__gcd(i,j));
            }
        }

        cout<<ans<<"\n";

    }

}