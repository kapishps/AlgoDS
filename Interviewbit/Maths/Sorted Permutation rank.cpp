typedef long long ll;
ll fenwickTree[256],fact[1000003];
int n;

inline void add(ll x, ll val) {
    while(x <= 255){
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

int Solution::findRank(string A) {
    n = A.size();
    fact[0] = 1;
    for (int i = 0; i < A.size(); ++i) {
        fact[i + 1] = (i + 1) * fact[i];
        fact[i + 1] %= 1000003;
        add(A[i], 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += ((fact[n - i - 1] * sum(A[i] - 1)) % 1000003) % 1000003;
        ans %= 1000003;
        add(A[i], -1);
    }

    return ans + 1;
}
