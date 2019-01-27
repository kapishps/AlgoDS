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
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

ll arr[MAXN];

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
    cin >> t;
    while (t--) {
        ll a, b, c, d, m, n;
        cin >> a >> b >> c >> d >> m >> n;

        ll newm = m;
        while (newm < 1e14) {
            newm *= 2;
        }

        map<ll, ll> lhs, rhs;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            arr[i] += newm;
            arr[i] %= m;

            lhs[power_mod(arr[i], 2, m)]++;

            ll A = (a * power_mod(arr[i], 3, m)) % m;
            ll B = (b * power_mod(arr[i], 2, m)) % m;
            ll C = (c * arr[i]) % m;
            rhs[(A + B + C + d + newm) % m]++;
        }

        ll ans = 0;
        for (auto i: lhs) {
            if (present(rhs, i.first)) {
                ans += (i.second * rhs[i.first]) % MOD;
                ans %= MOD;
            }
        }
        cout << ans << "\n";

    }

    return 0;
}