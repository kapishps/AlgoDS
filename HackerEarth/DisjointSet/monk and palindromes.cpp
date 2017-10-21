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

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

ll parent[MAXN],rnk[MAXN];

int findset(int x) {
    if (x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int u,int v) {
    int pu = findset(u);
    int pv = findset(v);
    if (pu != pv) {
        parent[pv] = pu;
        rnk[pu] += rnk[pv];
    }
}

//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/monk-and-palindromes/

int main() {
    FastIO;
    ll n,m;
    cin>>n>>m;
    for (int i = 0; i <=n; ++i) {
        parent[i] =i;
        rnk[i] =1;
    }
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin>>u>>v;
        int l = v-u;
        for (int j = 0; j <=(l/2); ++j) {
            unionset(u+j,v-j);
        }
    }
    vector<int> visited(n+1,0);
    ll ans=1;
    for (int i = 1; i <=n; ++i) {
        if(!visited[findset(i)]) {
            visited[findset(i)]=1;
            ans *= 10;
            ans %= MOD;
        }
    }
    cout<<ans;
    return 0;
}