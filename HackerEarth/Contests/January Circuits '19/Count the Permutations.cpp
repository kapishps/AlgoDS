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

ll A[MAXN],B[MAXN], sml[MAXN];
map<ll,ll> Map1;
ll ft[MAXN],fact[MAXN];
int n;

void add(ll x, ll val) {
    while(x <= MAXN){
        ft[x] += val;
        x += x & -x;
    }
}

// sum[0,i]
ll sum(ll x) {
    ll ret = 0;
    while(x > 0){
        ret += ft[x];
        x -= x & -x;
    }
    return ret;
}

ll mul_mod(ll a, ll b, ll M = MOD) {        //(a * b) % M
    a %= M;
    b %= M;
    return (a*b) % M;
}

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

ll modulo_inv(ll n, ll M = MOD){      //using Fermat's Little Theorem.
    return power_mod(n, M - 2, M);
}


ll rankOfPerm(ll n) {
    fact[0] = 1;
    for (int i = 0; i < n; ++i) {
        Map1[sml[i]]++;
        fact[i + 1] = (i + 1) * fact[i];
        fact[i + 1] %= MOD;
    }

    ll Denom = 1;
    for (auto i:Map1) {
        add(i.first, i.second);
        Denom *= fact[i.second];
        Denom %= MOD;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (((fact[n - i - 1] * sum(sml[i] - 1)) % MOD) * modulo_inv(Denom)) % MOD;
        ans %= MOD;
        Denom *= modulo_inv(Map1[sml[i]]);
        Denom %= MOD;
        Map1[sml[i]]--;
        add(sml[i], -1);
    }

    return ans + 1;
}

int main() {
    FastIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        Map1[A[i]]++;
    }

    int k = 0, flag = 0, flag2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
        if (Map1[B[i]] > 0 && flag == 0) {
            sml[k++] = B[i];
            Map1[B[i]]--;
        } else if (flag == 0) {
            flag = 1;
            ll t = -inf;
            for (auto j : Map1) {
                if (j.second > 0 && j.first < B[i])
                    t = max(t, j.first);
            }

            if (t == -inf) {
                flag2 = 1;
            } else {
                sml[k++] = t;
                Map1[t]--;
            }
        }
    }

    if (flag == 1) {
        int j = k;
        for (auto i: Map1) {
            while (i.second > 0) {
                sml[k++] = i.first;
                i.second--;
            }
        }

        if (flag2) {
            sort(sml + j, sml + n);
            prev_permutation(sml, sml + n);
        }
        else
            sort(sml + j, sml + n, greater<ll>());
    }
    else {
        prev_permutation(sml, sml + n);
    }

    assert(lexicographical_compare(sml, sml + n, B, B + n) == true);

    Map1.clear();
    cout << rankOfPerm(n);

    return 0;
}