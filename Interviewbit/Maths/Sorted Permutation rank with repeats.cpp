typedef long long ll;
ll fenwickTree[256] = {0} ,fact[1000009] = {0};
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

ll mul_mod(ll a, ll b, ll M = 1000003) {        //(a * b) % M
    a %= M;
    b %= M;
    return (a*b) % M;
}

ll power_mod(ll a, ll p, ll M = 1000003) {      //n^p % M
    ll x = a, res = 1;
    while (p) {
        if (p & 1)
            res = mul_mod(res, x, M);
        x = mul_mod(x, x, M);
        p >>= 1LL;
    }
    return res;
}

ll modulo_inv(ll n, ll M = 1000003){      //using Fermat's Little Theorem.
    return power_mod(n, M - 2, M);
}


int Solution::findRank(string sml) {
    fact[0] = 1;
    map<int,int> Map1;
    n = sml.size();
    for (int i = 0; i < n; ++i) {
        Map1[sml[i]]++;
        fact[i + 1] = (i + 1) * fact[i];
        fact[i + 1] %= 1000003;
    }

    ll Denom = 1;
    for (auto i:Map1) {
        add(i.first, i.second);
        Denom *= fact[i.second];
        Denom %= 1000003;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (((fact[n - i - 1] * sum(sml[i] - 1)) % 1000003) * modulo_inv(Denom)) % 1000003;
        ans %= 1000003;
        Denom *= modulo_inv(Map1[sml[i]]);
        Denom %= 1000003;
        Map1[sml[i]]--;
        add(sml[i], -1);
    }

    return ans + 1;
}