#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

ll graph[405][405],dist[405][405];

void floyd_warshall(int n) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == j)
                dist[i][j] = 0;
            else if(graph[i][j] != 0)
                dist[i][j] = graph[i][j];
            else
                dist[i][j] = inf;
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

//https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/

int main() {
    Boost;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x-1][y-1] = w;
    }
    floyd_warshall(n);
    int q;
    cin>>q;
    while (q--){
        int x,y;
        cin>>x>>y;
        if(dist[x-1][y-1]==inf)
            cout<<-1<<"\n";
        else
            cout<<dist[x-1][y-1]<<"\n";
    }
    return 0;
}
