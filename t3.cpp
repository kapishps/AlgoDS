#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <unordered_set>
#include <iomanip>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

int parent[MAXN],rnk[MAXN];

int findparent(int x) {
    if (x != parent[x])
        parent[x] = findparent(parent[x]);
    return parent[x];
}

void unionset(int x, int y) {
    int px = findparent(x), py = findparent(y);
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

int main() {
    Boost;
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u;
        rnk[--u] = 1;
    }
    for (int j = 0; j < x; ++j) {
        cin >> u >> v;
        unionset(--u, --v);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += rnk[findparent(i)];
    }
    cout << ans;
    return 0;
}
