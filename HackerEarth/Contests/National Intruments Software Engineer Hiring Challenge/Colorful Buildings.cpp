#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 5e5+9;

//Modular Multiplication
ll mul_mod(ll a, ll b, ll M = MOD) {        //(a * b) % M
    if (a < b)
        swap(a, b);
    ll res = 0, x = a;
    while (b > 0) {
        if (b & 1) {
            res = (res + x)%M;
        }
        x = (x * 2)%M;
        b >>= 1LL;
    }
    return res % M;
}

//Modular Exponentiation
ll power_mod(ll a, ll p, ll M = MOD) {      //n^p % M
    ll x = a, res = 1;
    while (p) {
        if (p & 1)
            res = mul_mod(res, x, M);
        x = mul_mod(x, x, M);
        p >>= 1LL;
    }
    return res;
}

int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        cout<<mul_mod(k,power_mod(k-1,n-1))<<"\n";
    }
    return 0;
}
