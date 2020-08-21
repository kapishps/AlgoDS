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

vector<pii> f,s,curr;
set<pii> v;
vector<int> graph[MAXN];
bool visited[MAXN];
int a,b;

void dfs(int src){
    if(src == b){
        if(f.size() == 0){
            f = curr;
        }
        else{
            s = curr;
        }
        return;
    }
    visited[src] = true;
    for(auto i: graph[src]){
        if(!visited[i]){
            curr.push_back({min(src,i),max(src,i)});
            dfs(i);
            curr.pop_back();
        }
    }
    visited[src] = false;
}

int main() {
    FastIO;
    int n,m;
    cin>>n>>m;
    assert(n == m);
    cin>>a>>b;
    a--;b--;
    for(int i =0; i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(a);

    if(s.size() == 0)
        cout<<f.size();
    else{
        for(auto i:f){
            v.insert(i);
        }
        for(auto i:s){
            v.insert(i);
        }
        cout<<f.size() + s.size() - v.size();
    }
}