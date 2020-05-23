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


ll solve(ll n, ll k){
    ll sum = (n*(n+1))/2;
    ll t = k;
    while(t <= n){
        ll s = n/t;
        sum = sum - (k-1)*(s*(s+1))/2;
        t *= k;
    }
    return sum;
}

int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<"\n";
    }
    return 0;
}