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


int main() {
    FastIO;
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int i = 0, ans = 0;
        while (i < s.size()) {
            if (s[i] == '1') {
                int flag=0;
                i++;
                while (i < s.size() && s[i] == '0') {
                    flag=1;
                    i++;
                }
                if (i < s.size() && s[i] == '1' && flag)
                    ans++;
            }
            else
                i++;
        }
        cout << ans << "\n";
    }
    return 0;
}