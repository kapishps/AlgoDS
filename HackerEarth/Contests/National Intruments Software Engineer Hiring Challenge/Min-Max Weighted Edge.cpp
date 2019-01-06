#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

vector<int> graph[MAXN];
ll deg[MAXN];
bool visited[MAXN];
map<ll,ll> M;

ll find_centre(ll src, ll n){
    queue<ll> qu;
    ll ans;
    for (int i = 1; i <= n; ++i) {
        if(deg[i] == 1)
            qu.push(i);
    }
    while(!qu.empty()){
        int t = qu.front();
        deg[t]--;
        ans = t;
        qu.pop();
        for(auto i: graph[t]){
            deg[i]--;
            if(deg[i]==1)
                qu.push(i);
        }
    }
    return ans;
}

void dfs(int src,int depth){
    visited[src] = 1;
    if(graph[src].size() == 1)
        M[depth]++;
    for(auto i:graph[src]){
        if(!visited[i])
            dfs(i,depth+1);
    }
}

int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;

        M.clear();
        for (int i = 0; i <= n; ++i) {
            graph[i].clear();
            visited[i] = 0;
            deg[i] = 0;
        }

        for (int i = 0; i < n - 1; ++i) {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        ll centre = find_centre(1,n);
        dfs(centre,1);

        if(M.size() == 1){
            int ans = s/(n-1);
            if(s%(n-1)!= 0)
                ans++;
            cout<<ans<<"\n";
        }
        else if(M.size() == 2 && M.rbegin()->second == 1){
            int ans = s/(n-1);
            if(s%(n-1) != 0)
                ans++;
            cout<<ans<<"\n";
        }
        else
            cout<<0<<"\n";
    }
    return 0;
}
