#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = INFINITY;
const int MOD = 1e9+7;
const int MAXN = 1e5+5;
const int LGNMAX = 20;

int parent[LGNMAX][MAXN];
vector<int> graph[MAXN],depth(MAXN),subtree;
ll data[MAXN][3];

void dfs(int curr){
    for(auto a:graph[curr]){
        depth[a] = depth[curr] + 1;
        dfs(a);
    }
}

void dfs2(int curr){
    subtree.pb(curr);
    for(auto a:graph[curr]){
        dfs2(a);
    }
}

void dfs3(int src){
    ll n=0,d=0,d2=0;
    int count=0;
    for(auto a:graph[src]){
        count++;
        dfs3(a);
        n+=data[a][0];
        d+=(data[a][1]+data[a][0]);
        d2+=(data[a][2])+(2*data[a][1])+data[a][0];
    }
    data[src][0]=n+1;
    data[src][1]=d;
    data[src][2]=d2;
}

int getparent(int u, int k) {
    for (int i = 0; i < LGNMAX; ++i) {
        if (k & 1) u = parent[i][u];
        k >>= 1;
    }
    return u;
}

int LCA(int u, int v) {
    // Adjust the heights
    if (depth[u] > depth[v]) {
        u = getparent(u, depth[u] - depth[v]);
    } else if (depth[v] > depth[u]) {
        v = getparent(v, depth[v] - depth[u]);
    }
    // If the vertices are now same, we are done
    if (u == v) return u;
    // Go as far up as you can such that vertices are different
    for (int i = LGNMAX - 1; i >= 0; i--) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    // Parent of u (or v) is now LCA
    return parent[0][u];
}

int main() {
    Boost;
    int n;
    cin>>n;
    memset(parent, -1, sizeof parent);
    for (int i = 2; i <=n; ++i) {
        cin>>parent[0][i];
        graph[parent[0][i]].pb(i);
    }
    for (int i = 1; i < LGNMAX; ++i) {
        for (int j = 2; j <=n; ++j) {
            if (parent[i - 1][j] != -1) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }
    dfs(1);
    dfs3(1);
//    for (int i = 1; i <=n; ++i) {
//        cout<<data[i][0]<<":"<<data[i][1]<<":"<<data[i][2]<<" ";
//    }
    int q,u,v,lca,k;
    cin>>q;
    for (int i = 0; i < q; ++i) {
        cin>>u>>v;
        lca = LCA(u,v);
        ll result=0;
        if(lca==v) {
            result = data[u][2];
            int temp=u;
            while(temp!=v){
                int p=parent[0][temp];
                for(auto a:graph[p]){
                    if(a!=temp){
                        k=depth[u]-depth[p];
                        k+=depth[a]-depth[p];
                        result+= data[a][2] + (k*k*data[a][0]) + (2*k*data[a][1]);
                    }
                    else{
                        k= (depth[u]-depth[p]);
                        result+= k*k;
                    }
                }
                temp=parent[0][temp];
            }
            cout << result << "\n";
        }
        else{
            k=depth[u]-depth[lca];
            k+=depth[v]-depth[lca];
            result = data[v][2] + (k*k*data[v][0]) + (2*k*data[v][1]);
            cout << result << "\n";
        }
    }
}
