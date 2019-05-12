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
const int MAXN = 1e6+9;

int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        ll last[10] = {0};
        vector<ll> ans[10];
        ll map1[MAXN][10] = {0};

        for (int i = s.size() - 1; i >= 0; i--) {
            if (i < s.size() - 1) {
                for (int j = 0; j < 10; ++j) {
                    map1[i][j] = map1[i + 1][j];
                }
                if(last[s[i] - '0'] != 0){
                    ll temp = map1[last[s[i] - '0']][s[i] - '0' + 1];
                    ans[s[i] - '0'].push_back(temp * (temp - 1L) / 2L);
                }
            }
            map1[i][s[i] - '0']++;
            last[s[i] - '0'] = i;
        }

        ll sum = 0;
        for (int i = 0; i < 9; ++i) {
            ll temp = ans[i].size();
            for (ll j = 0; j < temp; ++j) {
                sum += (ans[i][j] % MOD) * (temp - j);
                sum %= MOD;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}