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
const int MAXN = 1e5+9;

vector<int> graph[MAXN];
vector<pii> edgelist;
bool visited[MAXN];
set<pii> dirFinalised;


void dfs(int src,int parent){
    visited[src] = true;

    for(auto i: graph[src]){
        if(!visited[i])
            dfs(i,src);
    }

    vector<int> temp;
    for(auto i: graph[src]){
        if(i != parent && !present(dirFinalised, make_pair(src,i)) && !present(dirFinalised, make_pair(i,src))){
            temp.push_back(i);
        }
    }

    if(temp.size()%2 == 0){
        for(auto i: temp){
            dirFinalised.insert(make_pair(i,src));
        }
        dirFinalised.insert(make_pair(src,parent));
    }
    else{
        for(auto i: temp){
            dirFinalised.insert(make_pair(i,src));
        }
        dirFinalised.insert(make_pair(parent,src));
    }
}

//1
//4 6
//1 2
//1 3
//1 4
//2 3
//2 4
//3 4


int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        edgelist.clear();
        dirFinalised.clear();
        for (int i = 0; i <= n; ++i) {
            graph[i].clear();
            visited[i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            int u,v;
            cin>>u>>v;
            edgelist.push_back(make_pair(u,v));
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(m%2 == 1){
            cout<<-1<<"\n";
        }
        else{
            dfs(1,0);
//            for(auto i: dirFinalised){
//                cout<<i.first<<" "<<i.second<<"\n";
//            }
            for(auto i: edgelist){
                if(present(dirFinalised,i))
                    cout<<0<<" ";
                else
                    cout<<1<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
