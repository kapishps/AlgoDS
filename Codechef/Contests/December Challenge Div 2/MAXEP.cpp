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
//    FastIO;
    int n, c;
    cin >> n >> c;

    int total = 1000;
    int lo = 1, ans = 0, x = 0;
    while (x == 0) {
        int mid = min(lo + 400, n);

        cout << 1 << " " << mid << "\n";
        fflush(stdout);
        total--;

        cin >> x;

        if (x == 0) {
            ans = mid;
            lo = mid+1;
        }
        if (x == 1) {
            cout << 2 << "\n";
            fflush(stdout);
        }
    }

    x = 0;
    while (x == 0) {
        ans++;
        cout << 1 << " " << ans << "\n";
        fflush(stdout);
        cin >> x;
    }

    cout << 3 << " " << ans << "\n";
    fflush(stdout);

    return 0;
}