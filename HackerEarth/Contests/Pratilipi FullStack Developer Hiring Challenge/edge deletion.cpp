#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll w[100009], ans=0, k;
vector<ll> adj[100009];


ll dfs(ll u, ll p) {
    ll sum = 0;
    vector<ll> v;
    for (auto e : adj[u]) {
        if (e == p)
            continue;
        dfs(e, u);
        sum += w[e];
        v.push_back(w[e]);

    }
    sort(v.rbegin(), v.rend());
    for (auto t : v) {
        if (sum + w[u] > k) {
            ans++;
            sum -= t;
        }
        else return w[u] = sum + w[u];
    }
    return w[u];
}

int main() {
    ll n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    cout << ans;

    return 0;
}