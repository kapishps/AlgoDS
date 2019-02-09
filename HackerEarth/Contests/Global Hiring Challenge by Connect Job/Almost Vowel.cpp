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

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        vector<pii> v;
        ll c = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (isVowel(str[i]))
                c++;
            else {
                v.push_back({i - c, i - 1});
                c = 0;
            }
        }
        if (c > 0) {
            v.push_back({str.size() - c, str.size() - 1});
        }

        int ans = 0;
        if (v.size() >= 2) {
            if (v[0].first == 0 && v[v.size() - 1].second == str.size() - 1) {
                for (int i = 1; i < v.size() - 1; ++i) {
                    ans = max(ans, v[i].second - v[i].first + 1);
                }
                ans += v[0].second - v[0].first + 1;
                ans += v[v.size() - 1].second - v[v.size() - 1].first + 1;
            } else if (v[0].first == 0) {
                for (int i = 1; i < v.size(); ++i) {
                    ans = max(ans, v[i].second - v[i].first + 1);
                }
                ans += v[0].second - v[0].first + 1;
            } else if (v[v.size() - 1].second == str.size() - 1) {
                for (int i = 0; i < v.size() - 1; ++i) {
                    ans = max(ans, v[i].second - v[i].first + 1);
                }
                ans += v[v.size() - 1].second - v[v.size() - 1].first + 1;
            } else {
                for (int i = 0; i < v.size(); ++i) {
                    ans = max(ans, v[i].second - v[i].first + 1);
                }
            }
            cout << ans << "\n";
        } else if (v.size() == 1) {
            cout << v[0].second - v[0].first + 1 << "\n";
        } else
            cout << ans << "\n";

    }
    return 0;
}