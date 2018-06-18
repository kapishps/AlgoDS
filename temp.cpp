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

typedef struct node {
    int s, e, val, pos, q;

    bool operator<(const node &n) const {
        if (e != n.e) return e < n.e;
        return val > n.val;
    }

    node() {};

    node(int ss, int ee, int v, int p, int que) {
        s = ss, e = ee, val = v, pos = p, q = que;
    }
} vertice;

ll bit[MAXN], n, ans[3*MAXN];
map<ll,ll> occs,last;
vector<vertice> v;


void update(ll x, ll val){
    while(x <= n){
        bit[x] += val;
        x += x & -x;
    }
}

ll query(ll x){
    ll ret = 0;
    while(x > 0){
        ret += bit[x];
        x -= x & -x;
    }
    return ret;
}

int main() {
    FastIO;
    int q, s, e;
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>s;
        v.push_back(vertice(i, i, s, -1, 0));
    }
    cin>>q;
    for (int i = 0; i < q; i++) {
        cin>>s>>e;
        v.push_back(vertice(s, e, -inf, i, 1));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (v[i].q == 1) {
            ll num = query(v[i].e) - query(v[i].s - 1);
            ans[v[i].pos] = v[i].e - v[i].s + 1 - num;
        } else {
            if (present(occs, v[i].val)) {
                if (present(last, v[i].val))
                    update(last[v[i].val], -1);
                update(occs[v[i].val], 2);
                last[v[i].val] = occs[v[i].val];
            }
            //update(v[i].s, 1);
            occs[v[i].val] = v[i].s;
        }
    }

    for (ll i = 0; i < q; i++) {
        cout<<ans[i]<<"\n";
    }

}