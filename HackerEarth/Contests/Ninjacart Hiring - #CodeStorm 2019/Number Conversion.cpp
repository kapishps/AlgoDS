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

ll A[MAXN],P[MAXN],Q[MAXN];

int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        ll maxA = inf, minA = -inf;
        for (int i = 0; i < n; ++i) {
            cin >> P[i];
            maxA = min(maxA, A[i] + P[i]);
        }
        for (int i = 0; i < n; ++i) {
            cin >> Q[i];
            minA = max(minA, A[i] - Q[i]);
        }
        cout << max(0LL, maxA - minA + 1) << "\n";
    }
    return 0;
}