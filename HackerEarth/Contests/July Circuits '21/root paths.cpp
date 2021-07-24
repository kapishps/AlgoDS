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
const int MAXN = 1e6+9;

int ans[MAXN];
bitset<MAXN> visited;
vector<int> graph[MAXN];

void dfs(int x){
    visited[x] = 1;
    for(auto i:graph[x]){
        if(!visited[i])
            dfs(i);
    }
    return;
}

int solve(int x){
    if(visited[x]){
        return x;
    }
    return 0;
}

int main() {
    FastIO;
    ll n,q,t,lastans = 0;
    cin>>n>>q>>t;
    visited[1] = 1;
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            ll u,v;
            cin>>u>>v;
            u = (u^(t*lastans))%n;
            v = (v^(t*lastans))%n;
            u++; v++;
            graph[u].push_back(v);
            if(visited[u]){
                dfs(v);
            }
        }
        else {
            ll x;
            cin>>x;
            x = (x^(t*lastans))%n;
            x++;
            lastans = solve(x);
            cout<<lastans<<"\n";
        }
    }

}