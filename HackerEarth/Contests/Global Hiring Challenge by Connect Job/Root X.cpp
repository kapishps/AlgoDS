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

vector<pii> nodes;
vector<pii > graph[MAXN];
int cn[MAXN],dep[MAXN],seg[4*MAXN],a[MAXN],in[MAXN],ht[MAXN];
vector< pair<ll,pair<ll,pair<ll,ll>>> > qry;
int par[MAXN];
int ans[MAXN];


void build(ll si,ll st,ll en) {
    if (st == en) {
        seg[si] = a[st];
        return;
    }
    ll mi = (st + en) / 2;
    build(2 * si, st, mi);
    build(2 * si + 1, mi + 1, en);
    seg[si] = seg[2 * si] + seg[2 * si + 1];
}

void upd(ll si,ll st,ll en,ll id,ll v) {
    if (st == en) {
        seg[si] = v;
        return;
    }
    ll mi = (st + en) / 2;
    if (id <= mi)
        upd(2 * si, st, mi, id, v);
    else
        upd(2 * si + 1, mi + 1, en, id, v);
    seg[si] = seg[2 * si] + seg[2 * si + 1];
}

ll go(ll si,ll st,ll en,ll l,ll r) {
    if (l > r)
        return 0;
    if (st > r || en < l)
        return 0;
    if (l <= st && r >= en)
        return seg[si];
    ll mi = (st + en) / 2;
    return (go(2 * si, st, mi, l, r) + go(2 * si + 1, mi + 1, en, l, r));
}

ll dfs(ll s,ll pa=0) {
    ll sz = 1, mx = -1;
    cn[s] = -1;
    par[s] = pa;
    for (auto i:graph[s]) {
        if (i.first == pa)
            continue;
        dep[i.first] = dep[s] + 1;
        ll s1 = dfs(i.first, s);
        sz += s1;
        if (s1 > mx) {
            mx = s1;
            cn[s] = i.first;
            ht[s] = i.second;
        }
    }
    return sz;
}

ll tim=0;
void hld(ll src,ll top,ll wt,ll prev=0) {
    tim += 1;
    in[src] = tim;
    a[tim] = 0;
    if (cn[src] >= 0) {
        hld(cn[src], top, ht[src], src);
        for (auto i:graph[src]) {
            if (i.first == prev || i.first == cn[src])
                continue;
            hld(i.first, i.first, i.second, src);
        }
    }
    cn[src] = top;
}

ll lca(ll u,ll v) {
    ll re = 0;
    while (cn[u] != cn[v]) {
        if (dep[cn[u]] > dep[cn[v]]) {
            re += go(1, 1, tim, in[cn[u]], in[u]);
            u = par[cn[u]];
        } else {
            re += go(1, 1, tim, in[cn[v]], in[v]);
            v = par[cn[v]];
        }
    }
    if (dep[u] > dep[v])
        swap(u, v);
    re += go(1, 1, tim, in[u], in[v]);
    return re;
}

int main() {
    FastIO;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nodes.push_back({x, i + 1});
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 0});
    }

    for (int i = 0; i < q; ++i) {
        int v, w;
        cin >> v >> w;
        qry.push_back({w, {i, {1, v}}});
    }

    sort(nodes.begin(), nodes.end());
    sort(qry.begin(), qry.end());
    dep[1] = 0;
    dfs(1);
    hld(1, 1, 0);
    build(1, 1, tim);

    int j = 0;
    for (int i = 0; i < q; ++i) {
        int u = qry[i].second.second.first;
        int v = qry[i].second.second.second;
        int w = qry[i].first;
        int idx = qry[i].second.first;

        pii z = {w + 1, -inf};

        int t = lower_bound(nodes.begin(), nodes.end(), z) - nodes.begin();

        while (j < t) {
            ll x = nodes[j].first;
            ll y = nodes[j].second;
            upd(1, 1, tim, in[y], 1);
            j++;
        }

        ans[idx] = lca(u, v);
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}