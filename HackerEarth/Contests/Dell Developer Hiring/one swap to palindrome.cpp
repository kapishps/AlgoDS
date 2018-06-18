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


int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int frq[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            frq[s[i] - 'a']++;
        }
        int oddes = 0;
        for (int i = 0; i < 26; ++i) {
            if (frq[i] % 2 != 0)
                oddes++;
        }
        if (oddes > 1) {
            cout << "No" << "\n";
            continue;
        }

        set<char> set1;
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                set1.insert(s[i]);
                set1.insert(s[s.size() - i - 1]);
            }
        }
        if (set1.size() > 2) {
            cout << "No" << "\n";
            continue;
        }
        cout << "Yes" << "\n";
    }
    return 0;
}