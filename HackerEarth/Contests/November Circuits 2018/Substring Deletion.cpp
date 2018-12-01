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
const int MAXN = 1e5+9;

set<int> Set,l;


int main() {
    FastIO;
    string s;
    while (cin >> s) {
        vector<int> M[26];
        string ans;
        for (int i = 0; i < s.size(); ++i) {
            Set.insert(s[i] - 'a');
            M[s[i] - 'a'].push_back(i);
        }

        for (int i = 0; i < 26; ++i) {
            if (M[i].size() > 0) {
                l.insert(M[i][M[i].size() - 1]);
            }
        }

        int start = 0;
        int r = Set.size();
        while (r--) {
            for (auto i: Set) {
                int idx = lower_bound(M[i].begin(), M[i].end(), start) - M[i].begin();
                int x = M[i][idx];

                if (l.lower_bound(x) == l.begin()) {
                    ans += s[x];
                    start = x + 1;
                    l.erase(M[i][M[i].size() - 1]);
                    break;
                }
            }
            Set.erase(s[start - 1] - 'a');
        }
        cout << ans << "\n";
    }
}