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
const int MAXN = 2e5+9;

map<ll,ll> M;
ll pow2[100],sum[100];


ll nth_term(ll n) {
    if (n == 0)
        return 0;
    // if (present(M, n))
    //     return M[n];
    ll p = log2(n);
    return sum[p] + n - pow2[p] + nth_term(n - pow2[p]);
}


ll inline solve(ll n){
    ll lo = n/30, hi = 4e16;
    ll ans;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        ll temp = nth_term(mid);

        if (n < temp) {
            hi = mid;
            ans = mid;
        }
        else if (n == temp) {
            ans = mid;
            break;
        }
        else {
            lo = mid + 1;
        }
    }
    return ans;
}


int main() {
    FastIO;
    ll t;
    cin >> t;

    pow2[0] = 1, sum[0] = 1;
    ll i = 2, j = 1;
    while (i <= 1e18) {
        pow2[j] = i;
        sum[j] = (sum[j - 1]<<1LL) + (i>>1LL) - 1;
        j++;
        i <<= 1LL;
    }

    while (t--) {
        ll n;
        cin >> n;
        ll ans = solve(n);
        cout << ans << "\n";
    }

    return 0;
}