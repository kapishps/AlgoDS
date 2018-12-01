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
const int MAXN = 5e3+9;

ll n,k;
ll ans;
string s;

ll ispalindrome(string x){
//    cout<<x<<" ";
    string y = x;
    reverse(y.begin(),y.end());
    return y == x;
}

map<pair<int, pii>,ll> M;

ll solve(int i, int krem, int lastcut, ll ansi) {
    if (krem < 0 || i > n || (i == n && krem > 0)) {
        return 0;
    }
    if (krem == 0) {
        M[make_pair(i, make_pair(krem, lastcut))] = (ansi + ispalindrome(s.substr(lastcut, n - lastcut))) % MOD;
        ans += M[make_pair(i, make_pair(krem, lastcut))];
        ans %= MOD;
        return M[make_pair(i, make_pair(krem, lastcut))] % MOD;
    }
    if (present(M, make_pair(i, make_pair(krem, lastcut)))) {
        ans += M[make_pair(i, make_pair(krem, lastcut))];
        ans %= MOD;
        return M[make_pair(i, make_pair(krem, lastcut))] % MOD;
    }

    M[make_pair(i, make_pair(krem, lastcut))] =
            (solve(i + 1, krem - 1, i, ansi + ispalindrome(s.substr(lastcut, i - lastcut)))%MOD +
             solve(i + 1, krem, lastcut, ansi)%MOD) % MOD;
    return M[make_pair(i, make_pair(krem, lastcut))] % MOD;
}


int main() {
    FastIO;
    cin>>n>>k;
    cin>>s;
    solve(1,k,0,0);
    cout<<ans%MOD;
}