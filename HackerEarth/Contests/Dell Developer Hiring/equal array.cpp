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

ll a[MAXN]={0},b[MAXN]={0};

int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
            b[i] = b[i - 1] + a[i];
        }
        ll ans = 1e18;
        for (int i = 1; i <= n; ++i) {
            if (sum - b[i] >= b[i])
                ans = min(ans, (ll)(sum - b[i] - b[i]));
        }
        if (ans == 1e18)
            cout << "-1" << "\n";
        else
            cout << ans << "\n";
    }
    return 0;
}