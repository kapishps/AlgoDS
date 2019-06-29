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
#define all(x) begin(x), end(x)

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
    for (int i = 2; i < MAXN; ++i) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }
}

ll nCr(ll n, ll r) {
    return (fact[n] * modulo_inv((fact[r] * fact[n - r]) % MOD) ) % MOD;
}


int main() {
    FastIO;
    init();
    ll n, h1, h2, a, b, c;
    cin >> n >> h1 >> h2 >> a >> b >> c;

    ll A = a - c, B = b - c, C = h2 - h1 - (n * c);

    ll ans = 0, x, y, z;
    if(a == b && b == c ){
        if( (h2-h1) == a*n)
            ans = 1;
    }
    else if(a == b){
        if(C%B == 0 && C/B >= 0 && C/B <= n)
            ans = nCr(n, C/B);
    }
    else if(b == c){
        if(C%A == 0 && C/A >= 0 && C/A <= n)
            ans = nCr(n, C/A);
    }
    else if(a == c){
        if(C%B == 0 && C/B >= 0 && C/B <= n)
            ans = nCr(n, C/B);
    }
    else{
        for (int i = 0; i <= n; ++i) {
            if (B != 0 && (C - (A * i)) % B == 0) {
                x = i;
                y = (C - (A * i)) / B;
                z = n - x - y;
                if (y >= 0 && z >= 0) {
                    ans += (nCr(n, x) * nCr(n - x, y)) % MOD;
                    ans %= MOD;
                }
            }
        }
    }
    cout << ans;
}