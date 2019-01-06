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
const int MAXN = 2e5+9;

vector<pii> graph[MAXN];
vector<ll> segtree[4*MAXN];
ll cn[MAXN],in[MAXN],ht[MAXN],endpos[MAXN];
ll depth[MAXN],parent[MAXN];
ll a[MAXN],arr[MAXN];
map<ll,ll> Pos;

int lft,rght;

void build(ll si, ll st, ll en) {
    if (st == en) {
        segtree[si].emplace_back(a[st]);
        return;
    }
    ll mi = (st + en) / 2;
    build(2 * si, st, mi);
    build(2 * si + 1, mi + 1, en);

    merge(segtree[2*si].begin(),segtree[2*si].end(),segtree[2*si+1].begin(),segtree[2*si+1].end(),back_inserter(segtree[si]));
//    segtree[si] = segtree[2 * si] + segtree[2 * si + 1];
}

//void update_point(ll si, ll st, ll en, ll id, ll v) {
//    if (st == en) {
//        segtree[si] = v;
//        return;
//    }
//    ll mi = (st + en) / 2;
//    if (id <= mi)
//        update_point(2 * si, st, mi, id, v);
//    else
//        update_point(2 * si + 1, mi + 1, en, id, v);
//    segtree[si] = segtree[2 * si] + segtree[2 * si + 1];
//}

ll go(ll si, ll st, ll en, ll l, ll r) {
    if (l > r)
        return 0;
    if (st > r || en < l)
        return 0;
    if (l <= st && r >= en)
        return (segtree[si].order_of_key(rght+1)-segtree[si].order_of_key(lft));;
    ll mi = (st + en) / 2;
    return (go(2 * si, st, mi, l, r) + go(2 * si + 1, mi + 1, en, l, r));
}


ll dfs(ll src, ll prev=0) {
    ll tot_size = 1, max_size = -1;
    cn[src] = -1;
    parent[src] = prev;
    for (auto i:graph[src]) {
        if (i.first == prev)
            continue;
        depth[i.first] = depth[src] + 1;
        ll curr_size = dfs(i.first, src);
        tot_size += curr_size;
        if (curr_size > max_size) {
            max_size = curr_size;
            cn[src] = i.first;
            ht[src] = i.second;
        }
    }
    return tot_size;
}

ll tim=0;
void hld(ll src,ll top,ll wt,ll prev=0) {
    tim += 1;
    in[src] = tim;
    a[tim] = arr[src];
//    a[tim] = wt;
//    Pos[{prev,src}] = tim;
//    Pos[{src,prev}] = tim;
    if (cn[src] >= 0) {
        hld(cn[src], top, ht[src], src);
        for (auto i:graph[src]) {
            if (i.first == prev || i.first == cn[src])
                continue;
            hld(i.first, i.first, i.second, src);
        }
    }
    cn[src] = top;
    endpos[src] = tim;
}

ll fin(ll u,ll v) {
    ll re = 0;
    if(lft >= u && u <= rght)
        re--;
    if(lft >= v && v <= rght)
        re--;
    while (cn[u] != cn[v]) {
        if (depth[cn[u]] > depth[cn[v]]) {
            re += go(1, 1, tim, in[cn[u]], in[u]);
            u = parent[cn[u]];
        } else {
            re += go(1, 1, tim, in[cn[v]], in[v]);
            v = parent[cn[v]];
        }
    }
    if (depth[u] > depth[v])
        swap(u, v);
    re += go(1, 1, tim, in[u], in[v]);
    return re;
}

int main() {
    FastIO;
    int n, q, p, last = 0;
    cin >> n >> q>>p;

    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        arr[i] %= p;
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
//        edges.push_back({0, {i, {u, v}}});
        graph[u].push_back({v, 1});
        graph[v].push_back({u, 1});
    }

    depth[1] = 0;
    dfs(1);
    hld(1, 1, 0);
    build(1, 1, tim);

    for (int i = 0; i < q; ++i) {
        int u,v,l1,r1,l2,r2;
        cin>>u>>v>>l1>>r1>>l2>>r2;
        u ^= last;
        v ^= last;
        l1 ^= last;
        r1 ^= last;
        l2 ^= last;
        r2 ^= last;
        lft = l1;
        rght = r1;
        last = 1;
        last *= fin(u,v);
        lft = l2;
        rght = r2;
        last *= fin1(u,v);
        cout<<last<<"\n";
    }

    return 0;
}
