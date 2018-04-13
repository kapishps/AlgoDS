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

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

ll pref[MAXN],suff[MAXN],ans=1;

int main() {
    FastIO;
    string s;
    cin >> s;
    pref[0] = 1;
    suff[s.size() - 1] = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])
            pref[i] = pref[i - 1] + 1;
        else
            pref[i] = 1;
        ans += pref[i];
    }
    for (int i = s.size() - 2; i >= 0; i--) {
        if (s[i] == s[i + 1])
            suff[i] = suff[i + 1] + 1;
        else
            suff[i] = 1;
    }
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i - 1] == s[i + 1] && s[i - 1] != s[i]) {
            ans += min(pref[i - 1], suff[i + 1]);
        }
    }
    cout << ans << "\n";
    return 0;
}