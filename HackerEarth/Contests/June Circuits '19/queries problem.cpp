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
const int MAXN = 1e5+9;

ld a[MAXN], bit[MAXN];
ll n;
vector<pair<ld,int>> v;

void update(int ind, ld val) {
    while (ind < MAXN) {
        bit[ind] += val;
        ind += ind & (-ind);
    }
}

ld query(int ind) {
    ld sum = 0;
    while (ind > 0) {
        sum += bit[ind];
        ind -= ind & (-ind);
    }
    return sum;
}


ld val(int idx){
    return abs(2*query(idx) - query(n));
}

int solve(int lo, int hi) {
    int mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;

        if ((mid == 1 || val(mid - 1) > val(mid)) && (mid == n || val(mid + 1) >= val(mid)))
            return mid;
        else if (mid > 1 && val(mid - 1) > val(mid)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    FastIO;
    ll m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = log2l(a[i]);
        update(i + 1, a[i]);
    }

    ll t, p, v;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        if (t == 2) {
            cout << solve(1, n) << "\n";
        }
        else {
            cin >> p >> v;
            update(p, log2l(v));
        }
    }
}