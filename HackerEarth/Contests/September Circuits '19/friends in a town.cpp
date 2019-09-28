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
ll sum[MAXN], day[MAXN];
 
int main() {
    FastIO;
    ll n,m,k,q;
    cin>>n>>m>>k;
 
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    cin>>q;
    for (int i = 0; i <= n; ++i) {
        day[i] = inf;
    }
 
    for (int i = 1; i <= q; ++i) {
        ll p,x;
        cin>>p>>x;
 
        for(auto j : graph[p]){
            sum[j] += x;
            if(sum[j] >= k)
                day[j] = min(i*1LL, day[j]);
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        if(day[i] != inf)
            cout<<day[i]<<" ";
        else
            cout<<-1<<" ";
    }
}