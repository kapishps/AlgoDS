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

ll arr[MAXN];


int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        ll ns = 1e18, ans = 0;
        if (n <= 63) {
            ns = 1LL << (n - 1);
        }

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] >= ns)
                ans += arr[i]%MOD;
            ans %= MOD;
        }

        cout << ans % MOD<< "\n";
    }

    return 0;
}