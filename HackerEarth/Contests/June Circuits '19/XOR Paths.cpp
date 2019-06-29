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

vector<pii> graph[MAXN];
ll cnt[1<<18];
ll MOD2INV;

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

// Using Fast Walsh-Hadamard Transform
// https://github.com/mochow13/competitive-programming-library/blob/master/Math/Fast%20Walsh-Hadamard%20Transform.cpp

void transform(bool inv, int n) {
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0, m = d << 1; i < n; i += m) {
            for (int j = 0; j < d; j++) {
                if (inv) {
                    ll x = cnt[i + j], y = cnt[i + j + d];
                    cnt[i + j] = (((x + y) % MOD) * MOD2INV) % MOD;
                    cnt[i + j + d] = (((x - y) % MOD) * MOD2INV) % MOD; // xor
                    // cnt[i+j] = x-y // and
                    // cnt[i+j+d] = y-x // or
                } else {
                    ll x = cnt[i + j], y = cnt[i + j + d];
                    cnt[i + j] = (x + y) % MOD;
                    cnt[i + j + d] = (x - y) % MOD;    // xor
                    // cnt[i+j] = x+y // and
                    // cnt[i+j+d] = x+y // or
                }
            }
        }
    }
}

void dfs(int src, int parent, int x) {
    cnt[x]++;
    for(auto i : graph[src]){
        if(i.first == parent)
            continue;
        dfs(i.first, src, x ^ i.second);
    }
}

int toggleKthBit(int n, int k) {
    return (n ^ (1 << (k - 1)));
}

int main() {
    FastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    MOD2INV = modulo_inv(2, MOD) % MOD;
    dfs(0, -1, 0);
    transform(false, 1LL << 18);
    for (int i = 0; i < (1LL << 18); i++) {
        cnt[i] = cnt[i] * cnt[i];
        cnt[i] %= MOD;
    }
    transform(true, 1LL << 18);

    ll ans = 0;
    for (int i = 0; i < (1LL << 18); ++i) {
//        cout<<cnt[i]<<" ";
        ans += cnt[i]*cnt[i];
        ans %= MOD;
        for (int j = 1; j < 18; ++j) {
            ans += cnt[i]*cnt[toggleKthBit(i,j)];
            ans %= MOD;
        }
    }

    cout<<ans;
}