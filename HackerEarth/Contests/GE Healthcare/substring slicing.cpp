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

const long long inf = 1e18;
const int MOD = 1e9+7;
const int MAXN = 5e3+9;


int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int flag = 0;
        for (int i = 1; i < s.size(); ++i) {
            string x, y;
            x = s;
            reverse(x.begin(), x.end());
            if (x == s) {
                cout << "YES" << "\n";
                flag = 1;
                break;
            }
            y = s.substr(i, s.size() - i) + s.substr(0, i);
            x = y;
            reverse(x.begin(), x.end());
            if (x == y) {
                cout << "YES" << "\n";
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            cout << "NO" << "\n";
    }
}