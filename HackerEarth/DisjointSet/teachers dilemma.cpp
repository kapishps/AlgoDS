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

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

int parent[MAXN],rnk[MAXN];

int findset(int x) {
    if (x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y) {
    int px = findset(x), py = findset(y);
    if (px != py) {
        if (rnk[px] > rnk[py]) {
            parent[py] = px;
            rnk[px] += rnk[py];
        }
        else {
            parent[px] = py;
            rnk[py] += rnk[px];
        }
    }
}

void initialiseset(int start, int end) {
    for (int i = start; i <= end; ++i) {
        parent[i] = i;
        rnk[i] = 1;
    }
}

//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/teachers-dilemma-3/

int main() {
    FastIO;
    int n, m, u, v;
    cin >> n >> m;
    initialiseset(1, n);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        unionset(u, v);
    }
    bool visited[MAXN] = {0};
    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (!visited[findset(i)]) {
            visited[findset(i)] = 1;
            ans = (ans * rnk[findset(i)]) % MOD;
        }
    }
    cout << ans;
    return 0;
}