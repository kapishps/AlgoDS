#include<bits/stdc++.h>
using namespace std;

int a[200009],depth[200009];
vector<int> graph[200009], level[200009];
bool visited[200009];
int maxD;

void dfs(int src){
    visited[src] = true;
    for(auto i : graph[src]){
        if(!visited[i]){
            depth[i] = depth[src] + 1;
            level[depth[i]].push_back(a[i]);
            maxD = max(maxD, depth[i]);
            dfs(i);
        }
    }
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    level[0].push_back(a[1]);

    for (int i = 0; i <= n; i++) {
        sort(level[i].begin(), level[i].end());
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x %= (maxD + 1);
        int idx = lower_bound(level[x].begin(), level[x].end(), y) - level[x].begin();
        if (idx == level[x].size()) {
            cout << -1 << "\n";
        } else
            cout << level[x][idx] << "\n";
    }
}