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

vector<int> M[26];


int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            M[s[i] - 'a'].push_back(i);
            int x = M[s[i] - 'a'].size();
            int idx = lower_bound(M[s[i] - 'a'].begin(), M[s[i] - 'a'].end(), i - 2 * x - 1) - M[s[i] - 'a'].begin();
            for (int j = idx; j < x; ++j) {
                if (x - j <= ans / 2)
                    break;
                if (M[s[i] - 'a'][j] >= max(0, i - 2 * (x - j)))
                    ans = max(ans, min(n, 2 * (x - j) + 1));
            }
        }
        cout << ans << "\n";
        for (int i = 0; i < 26; ++i) {
            M[i].clear();
        }
    }

    return 0;
}