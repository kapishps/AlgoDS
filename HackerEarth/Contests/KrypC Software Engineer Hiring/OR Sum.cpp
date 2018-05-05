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

ll a[MAXN],pow2[MAXN];

void calc_pow2(int n){
    pow2[0]=1;
    for (int i = 1; i < n; ++i) {
        pow2[i] =2*pow2[i-1];
        pow2[i] %=MOD;
    }
}


int main() {
    FastIO;
    ll t, n;
    cin >> t;
    calc_pow2(MAXN);

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int bits[33] = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 32; ++j) {
                if (a[i] & (1LL << j))
                    bits[j]++;
            }
        }

        ll ans = 0;
        for (int i = 0; i < 32; ++i) {
            ll afected_subsets = (pow2[n] - pow2[n - bits[i]] + MOD) % MOD;
            ans += (pow2[i] * afected_subsets);
            ans %= MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}