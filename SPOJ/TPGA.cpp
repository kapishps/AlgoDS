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
const int MAXN = 2e5+9;

ll arr[MAXN];
ll fenwickTree[MAXN],fact[MAXN];
int n;

inline void add(ll x, ll val) {
    while(x <= n){
        fenwickTree[x] += val;
        x += x & -x;
    }
}

// sum[0,i]
inline ll sum(ll x) {
    ll ret = 0;
    while(x > 0){
        ret += fenwickTree[x];
        x -= x & -x;
    }
    return ret;
}


inline ll rankOfDistinctPerm(ll n) {
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += ((fact[n - i - 1] * sum(arr[i] - 1)) % MOD) % MOD;
        ans %= MOD;
        add(arr[i], -1);
    }

    return ans + 1;
}

// https://www.spoj.com/problems/TPGA/

int main() {
    int t;
    scanf("%d", &t);

    fact[0] = 1;
    for (int i = 0; i < MAXN - 5; ++i) {
        fact[i + 1] = (i + 1) * fact[i];
        fact[i + 1] %= MOD;
    }

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
            add(arr[i], 1);
        }
        printf("%lld\n", rankOfDistinctPerm(n));
    }

    return 0;
}