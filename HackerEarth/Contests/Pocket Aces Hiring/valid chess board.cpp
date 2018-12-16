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

map<unsigned long long, int> M;

int main() {
    FastIO;
    ll n, m;
    cin >> n >> m;

    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < n - 7; ++i) {
        for (int j = 0; j < m - 7; ++j) {
            string t;
            for (int k = 0; k < 8; ++k) {
                for (int l = 0; l < 8; ++l) {
                    t += s[i + k][j + l];
                }
            }
            if( t == "0101010110101010010101011010101001010101101010100101010110101010"
                || t == "1010101001010101101010100101010110101010010101011010101001010101")
                ans ++;
        }
    }
    cout << ans;
    return 0;
}