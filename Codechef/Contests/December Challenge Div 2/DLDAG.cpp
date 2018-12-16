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
const int MAXN = 1e6+9;

vector<int> graph[MAXN];
set<pii> n_graph[MAXN];
int indeg[MAXN],outdeg[MAXN];
bool visited[MAXN];
vector<int> topo;


void printvector( vector<int> v){
    cout<<"vector v= ";
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
}


void dfs(int src) {
    visited[src] = true;

    for (auto i: graph[src]) {
        n_graph[src].insert(make_pair(indeg[i], i));
    }

    for (auto i: n_graph[src]) {
//        cerr<<i.second<<" ";
        if (!visited[i.second]) {
            dfs(i.second);
        }
    }

    topo.push_back(src);

    return;
}

// 35/100 score

int main() {
    FastIO;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }


    vector<string> ans;
//    printvector(topo);
    for (int i = 0; i < topo.size(); ++i) {
        if (i != topo.size() - 1) {
            if (present(n_graph[topo[i + 1]], make_pair(indeg[topo[i]], topo[i])) ||
                present(n_graph[topo[i]], make_pair(indeg[topo[i + 1]], topo[i + 1]))) {
                ans.push_back(to_string(1) + " " + to_string(topo[i]));
            } else {
                ans.push_back(to_string(2) + " " + to_string(topo[i]) + " " + to_string(topo[i + 1]));
                i++;
            }
        } else {
            ans.push_back(to_string(1) + " " + to_string(topo[i]));
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}