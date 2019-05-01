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

class SegmentTree {                         // the segment tree is stored like a heap array
private:
    vector<ll> tree, lazy, A;
    int n;
    int left (int p) {                  // same as binary heap operations
        return p << 1;
    }
    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int node, int s, int e) {
        if (s == e) {
            tree[node] = A[s];
            return;
        }
        int mid = (s + e) / 2;
        build(left(node), s, mid);
        build(right(node), mid + 1, e);
        tree[node] = max(tree[left(node)], tree[right(node)]);
    }

    void updateRange(int node, int s, int e, int l, int r, ll val) {
        if (lazy[node] != 0) {
            tree[node] = lazy[node];
            if (s != e) {
                lazy[left(node)] = lazy[node];
                lazy[right(node)] = lazy[node];
            }
            lazy[node] = 0;
        }
        if (s > e || r < s || l > e)
            return;
        if (s >= l && e <= r) {
            tree[node] = val;
            if (s != e) {
                lazy[left(node)] = val;
                lazy[right(node)] = val;
            }
            return;
        }
        int mid = (s + e) / 2;
        updateRange(left(node), s, mid, l, r, val);
        updateRange(right(node), mid + 1, e, l, r, val);
        tree[node] = max(tree[left(node)], tree[right(node)]);
    }

    ll query(int node, int s, int e, int l, int r) {
        if (s > e || r < s || l > e)
            return 0;
        if (lazy[node] != 0) {
            tree[node] = lazy[node];
            if (s != e) {
                lazy[left(node)] = lazy[node];
                lazy[right(node)] = lazy[node];
            }
            lazy[node] = 0;
        }
        if (s >= l && e <= r)
            return tree[node];
        int mid = (s + e) / 2;
        ll p1 = query(left(node), s, mid, l, r), p2 = query(right(node), mid + 1, e, l, r);
        return max(p1, p2);
    }

public:
//    SegmentTree(const vector<ll> &_A) {
//        A = _A; n = (int)A.size();
//        tree.assign(4 * n, 0);               // create large enough vector of zeroes
//        lazy.assign(4 * n, 0);               // create large enough vector of zeroes
//        build(1, 0, n - 1);                  // recursive build
//    }

    SegmentTree(int _n) {
        n = _n;
        tree.assign(4 * n, 0);               // create large enough vector of zeroes
        lazy.assign(4 * n, 0);               // create large enough vector of zeroes
    }

    ll query(int i, int j) {
        return query(1, 0, n - 1, i, j);          // overloading
    }

    void updateRange(int l, int r, ll new_value) {
        return updateRange(1, 0, n - 1, l, r, new_value);
    }
};


int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int n,q;
        cin >> n >> q;
        SegmentTree st(n);

        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;
            if (x == 1) {
                ll a = st.query(y - 1, y + z - 1);
                st.updateRange(y - 1, y + z - 1, a + z);
            }
            else {
                cout << st.query(y - 1, z - 1) << "\n";
            }
        }
    }
}