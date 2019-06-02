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
const int MAXN = 3e5+9;

vector<ll> graph[MAXN];
vector<pair<ll,pair<ll,ll>>> edgelist;

ll parent[MAXN],rnk[MAXN];

ll findset(ll x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

ll unionset(ll x, ll y, ll w) {
    ll px = findset(x), py = findset(y);
    if (px != py) {
        if (rnk[px] > rnk[py]) {
            parent[py] = px;
            ll temp = rnk[px] * rnk[py];
            rnk[px] += rnk[py];
            return temp - 1;
        }
        else {
            parent[px] = py;
            ll temp = rnk[px] * rnk[py];
            rnk[py] += rnk[px];
            return temp - 1;
        }
    }
}

void initialiseset(int start, int end) {
    for (int i = start; i <= end; ++i) {
        parent[i] = i;
        rnk[i] = 1;
    }
}

ll power(ll x, ll y) {
    ll res = 1;     // Initialize result

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) {
            res = res * x;
            res %= 987654319L;
        }

        // n must be even now
        y = y >> 1; // y = y/2
        x = x * x;  // Change x to x^2
        x %= 987654319L;
    }
    return res;
}

int main() {
    FastIO;
    ll n, maxw;
    cin >> n >> maxw;


    int flag = 0;
    for (int i = 0; i < n - 1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;

        // assert(maxw - w + 2 > 0);
        if(w > maxw)
            flag = 1;
        edgelist.push_back({maxw - w + 2,{u,v}});
    }

    if(flag){
        cout<<0;
        return 0;
    }

    sort(edgelist.begin(),edgelist.end(), greater<pair<ll,pair<ll,ll>>>());
    initialiseset(0,n);

    ll ans = 1;
    for(auto i: edgelist){
        ll t = unionset(i.second.first,i.second.second, i.first);
        t = power(i.first, t);
        t %= 987654319L;
        ans *= t;
        ans %= 987654319L;
    }
    cout << ans;

}