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
const int MAXN = 2e6+9;

int parent[MAXN],mrnk[MAXN],wrnk[MAXN];
int x,y;

int findset(int n) {
    if (n != parent[n])
        parent[n] = findset(parent[n]);
    return parent[n];
}

void unionset(int u, int v){
    if(u>x){                    // w-w
        int pu = findset(u);
        int pv = findset(v);
        if(pu!=pv){
            if(wrnk[pu]>wrnk[pv]){
                parent[pv] = pu;
                wrnk[pu] +=wrnk[pv];
            }
            else{
                parent[pu] = pv;
                wrnk[pv] +=wrnk[pu];
            }
        }
    }
    else if(v>x){               // m-w
        int pu = findset(u);
        int pv = findset(v);
        if(pu!=pv){
            parent[pv] = pu;
            wrnk[pu] += wrnk[pv];
        }
    }
    else{                       // m-m
        int pu = findset(u);
        int pv = findset(v);
        if(pu!=pv){
            if(mrnk[pu]>mrnk[pv]){
                parent[pv] = pu;
                mrnk[pu] +=mrnk[pv];
            }
            else{
                parent[pu] = pv;
                mrnk[pv] +=mrnk[pu];
            }
        }
    }
}

//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/marriage-problem/

int main() {
    FastIO;
    cin>>x>>y;
    for (int i = 0; i <=x; ++i) {
        parent[i]=i;
        mrnk[i]=1;
        wrnk[i]=0;
    }
    for (int i = x+1; i <= x + y; ++i) {
        parent[i]=i;
        wrnk[i]=1;
    }
    int n,u,v;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>u>>v;
        unionset(u,v);
    }
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>u>>v;
        unionset(x+u,x+v);
    }
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>u>>v;
        unionset(u,x+v);
    }
    ll ans=0;
    for (int i = 1; i <=x; ++i) {
        int pu = findset(i);
        ans += (ll)(y - wrnk[pu]);
    }
    cout<<ans;
    return 0;
}