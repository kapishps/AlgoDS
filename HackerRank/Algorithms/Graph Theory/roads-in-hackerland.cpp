#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> edge;

const int MAXN=100010; //Imp to make size > 100009 otherwise WA.

vector<pair<int, edge>> edgelist;
vector<edge> tree[MAXN+1];
int parent[MAXN+1],rnk[MAXN+1],children[MAXN+1]={0};
bool visited[MAXN+1]={0};
long long cross[2*MAXN+1]={0};

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    x = findset(x), y = findset(y);
    if (rnk[x] > rnk[y]){
        parent[y]=x;
        rnk[x]+=rnk[y];
    }
    else{
        parent[x]= y;
        rnk[y]+=rnk[x];
    }
}

void Kruskal(){
    sort(edgelist.begin(),edgelist.end());
    for (int i = 0; i < edgelist.size(); ++i) {
        int pu= findset(edgelist[i].second.first);
        int pv= findset(edgelist[i].second.second);
        if(pu != pv){
            int x,y,w;
            x=edgelist[i].second.first;
            y=edgelist[i].second.second;
            w=edgelist[i].first;
            tree[x].push_back(make_pair(y,w));
            tree[y].push_back(make_pair(x,w));
            unionset(pu,pv);
        }
    }
}

int dfs(int n,int src=0){
    visited[src]= true;
    children[src]=1;
    for (int i = 0; i < tree[src].size(); ++i) {
        int curr=tree[src][i].first;
//        cout<<curr;
        if(!visited[curr]){
            int a=dfs(n,curr);
            cross[tree[src][i].second]+=(long long)a*(n-a);//Imp to make long long.
            children[src]+=a;
        }
    }
    return children[src];
}

//https://www.hackerrank.com/challenges/johnland

int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        edgelist.push_back(pair<int,edge>(w,edge(x,y)));
    }
    for(int i=0; i<=MAXN; i++){
        parent[i]=i;
        rnk[i]=1;
    }
    Kruskal();
    dfs(n,0);
    string ans;
    for (int i = 0; i <2*MAXN; ++i) {
        if(cross[i]%2==0){
            ans.push_back('0');
        }
        else
            ans.push_back('1');
        cross[i+1]+=cross[i]/2;
    }
    reverse(ans.begin(), ans.end());
    ans=ans.substr(ans.find("1"));
    cout<<ans;
    return 0;
}