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
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

ll a[MAXN], bit[MAXN];
ll n;

void update(int ind, ll val) {
    while (ind < MAXN) {
        bit[ind] += val;
        ind += ind & (-ind);
    }
}

ll query(int ind) {
    ll sum = 0;
    while (ind > 0) {
        sum += bit[ind];
        ind -= ind & (-ind);
    }
    return sum;
}

int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        ll sum = 0;
        memset(bit, 0, sizeof bit);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] > 0) {
                update(a[i], a[i]);
                sum += query(a[i] - 1);
            }
        }

        cout << sum << "\n";
    }

}