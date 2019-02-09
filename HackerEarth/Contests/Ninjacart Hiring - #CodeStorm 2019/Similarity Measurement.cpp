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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

int A[MAXN];
map<int, ordered_set> M;


int solve(int lo, int hi, int val) {
    if (lo >= hi)
        return *(M[A[val]].find_by_order(lo));
    int mid = (hi + lo) / 2;
    if (M[A[val]].order_of_key(val) - mid < val - *(M[A[val]].find_by_order(mid)))
        return solve(mid + 1, hi, val);
    return solve(lo, mid, val);
}


int main() {
    FastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        M[A[i]].insert(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int type, pos;
        cin >> type >> pos;
        pos--;
        if (type == 1) {
            int val;
            cin >> val;
            M[A[pos]].erase(pos);
            M[val].insert(pos);
            A[pos] = val;
        }
        else {
            cout << solve(0, M[A[pos]].order_of_key(pos), pos) + 1 << "\n";
        }
    }
    return 0;
}