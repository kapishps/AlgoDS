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

int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        map<int, int> map1, map2;
        for (int i = 0; i < n; ++i) {
            map1[a[i] - 'a']++;
            map2[b[i] - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += min(map1[i], map2[i]);
        }
        cout << ans << "\n";

    }
    return 0;
}