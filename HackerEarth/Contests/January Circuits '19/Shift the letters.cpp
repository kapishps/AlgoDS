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
const int MAXN = 1e5+9;

vector<int> v;
ll dist[2050][2050],dp[35][2050];
int n;


int main() {
    FastIO;
    string s;
    cin >> s;
    int k;
    cin >> k;

    v.push_back(s[0] - 'a');
    for (int i = 1; i < s.size(); ++i) {
        v.push_back(s[i] - 'a');
    }


    n = v.size();
    for (int i = 0; i < n; ++i) {
        ll t[26] = {0};
        for (int j = i; j < n; ++j) { ;
            ll ans = inf;
            for (int l = 0; l < 26; ++l) {
                t[l] += (l - v[j] + 26)%26;
                ans = min(ans,t[l]);
            }
            dist[i][j] = ans;
        }
    }

    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == 0){
                dp[i][j] = dist[i][j];
                continue;
            }
            ll ans = inf;
            for (int l = 0; l < j; ++l) {
                ans = min(ans, dp[i-1][l] + dist[l+1][j]);
            }
            dp[i][j] = ans;
        }
    }
    cout<<dp[k][n-1];
    return 0;
}