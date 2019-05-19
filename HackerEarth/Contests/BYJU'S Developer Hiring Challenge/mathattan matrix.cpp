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
const int MAXN = 1e6+9;

int a[509][509];
int dist[MAXN];

void solve(int n,int m ,int x, int y) {
    vector<int> graph[MAXN];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > 0) {
                for (int k = -a[i][j]; k <= a[i][j]; ++k) {
                    for (int l = -a[i][j]; l <= a[i][j]; ++l) {
                        if (abs(k) + abs(l) == a[i][j] && i + k >= 0 && j + l >= 0 && i + k < n && j + l < m) {
                            graph[(501 * i) + j].push_back((501 * (i + k)) + j + l);
                        }
                    }
                }
            }
        }
    }

    memset(dist, -1, sizeof(dist));

    int src = (501 * x) + y;
    cerr << graph[src].size();

    dist[src] = 0;
    queue<int> qu;
    qu.push(src);
    while (!qu.empty()) {
        int curr = qu.front();
        qu.pop();
        for (auto i: graph[curr]) {
            if (dist[i] == -1) {
                qu.push(i);
                dist[i] = dist[curr] + 1;
            }
        }
    }
}

int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        cin >> x >> y;
        solve(n, m, --x, --y);

        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            cout << dist[(501 * u) + v] << "\n";
        }

    }
    return 0;
}