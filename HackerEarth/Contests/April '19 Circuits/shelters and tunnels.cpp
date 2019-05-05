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
const int MAXN = 1e5+9;

vector<int> graph[MAXN];

int main() {
    FastIO;
    int n;
    cin>>n;
    for (int i = 0; i < n - 1; ++i) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    map<int,vector<int>> map1;
    int msize = 0;
    for (int i = 1; i <= n; ++i) {
        map1[graph[i].size()].push_back(i);
        msize = max(msize, (int) graph[i].size());
    }

    cout<<map1[msize].size()<<"\n";
    for(auto i: map1[msize]){
        cout<<i<<" ";
    }
    return 0;
}