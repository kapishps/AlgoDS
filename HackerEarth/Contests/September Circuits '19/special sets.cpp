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
 
ll fact[MAXN];
 
ll power_mod(ll num, ll pow, ll M = MOD) {        //n^p % M
    ll ret = 1;
    while (pow) {
        if (pow & 1) {
            ret = (ret * num) % M;
        }
        pow >>= 1LL;
        num = (num * num) % M;
    }
    return ret;
}
 
ll modulo_inv(ll n, ll M = MOD){      //using Fermat's Little Theorem.
    return power_mod(n, M - 2, M);
}
 
void init() {
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 2000; ++i) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }
}
 
ll nPr(ll n, ll r) {
    return (fact[n] * modulo_inv((fact[n - r]) % MOD) ) % MOD;
}
 
 
int main() {
    FastIO;
    ll n;
    cin>>n;
 
    init();
 
    ll ans = 0;
    for (ll i = 1; i <= (n+1)/2; ++i) {
        ans += nPr(n-i+1, i)%MOD;
        ans %= MOD;
    }
 
    cout<<ans;
}