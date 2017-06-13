#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e3+9;

//Range GCD

class SegmentTree {                         // the segment tree is stored like a heap array
private: vector<int> segtree, A;
    int n;
    int left (int p) {                  // same as binary heap operations
        return p << 1;
    }
    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {           // O(n log n)
        if (L == R)                             // as L == R, either one is fine
            segtree[p] = A[L];                  // store the value
        else {                                  // recursively compute the values
            build(left(p) , L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = segtree[left(p)], p2 = segtree[right(p)];
            segtree[p] = __gcd(p1,p2);
        }
    }

    int rgcd(int p, int L, int R, int i, int j) {                  // O(log n)
        if (i > R || j < L) return -1; // current segment outside query range
        if (L >= i && R <= j) return segtree[p];               // inside query range

        // compute the gcd in the left and right part of the interval
        int p1 = rgcd(left(p), L, (L + R) / 2, i, j);
        int p2 = rgcd(right(p), (L + R) / 2 + 1, R, i, j);

        if (p1 == -1) return p2;   // if we try to access segment outside query
        if (p2 == -1) return p1;                               // same as above
        return __gcd(p1,p2);           // as as in build routine
    }

public:
    SegmentTree(const vector<int> &_A) {
        A = _A; n = (int)A.size();              // copy content for local usage
        segtree.assign(4 * n, 0);               // create large enough vector of zeroes
        build(1, 0, n - 1);                     // recursive build
    }

    int rgcd(int i, int j) {
        return rgcd(1, 0, n - 1, i, j);          // overloading
    }

    void printsegtree(){
        for (int i = 0; i < segtree.size(); ++i) {
            cout<<segtree[i]<<" ";
        }
    }
};

//https://www.codechef.com/problems/GCDQ

int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        SegmentTree st(a);
        while(q--){
            int l,r;
            cin>>l>>r;
            l = st.rgcd(0, l - 2);
            r = st.rgcd(r, n - 1);
            if(l==-1)
                cout<<r<<"\n";
            else if(r==-1)
                cout<<l<<"\n";
            else
                cout<<__gcd(l,r)<<"\n";
        }
//        st.printsegtree();
    }
    return 0;
}