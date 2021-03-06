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

int arr[MAXN][256];

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j < 256; ++j) {
            if ((j & t) == j)
                arr[i][j] = 1 + arr[i - 1][j];
            else
                arr[i][j] = arr[i - 1][j];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        int a = __builtin_popcount(x);
        ll ans = 0;
        for (int i = x; i < 256; ++i) {
            if ((x & i) == x) {
                int b = __builtin_popcount(i);
                ans += pow(-1, b - a) * power_mod(arr[r][i] - arr[l - 1][i], 3);
                ans += MOD;
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
