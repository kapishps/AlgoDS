#include <iostream>
#include <map>

using namespace std;

const int MAXN=100000;
int parent[MAXN+1],ans[MAXN+1];
map<int,int> arr[MAXN+1],count;

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y,int j){
    int px = findset(x),py = findset(y);
    if (px != py) {
        if(arr[px].size() > arr[py].size()){
            parent[py]=px;
            for (auto a: arr[py]){
                arr[px][a.first] += a.second;
                if (arr[px][a.first] == count[a.first] && ans[a.first] == -1)
                    ans[a.first] = j+1;
            }
        }
        else{
            parent[px]=py;
            for (auto a: arr[px]){
                arr[py][a.first] += a.second;
                if (arr[py][a.first] == count[a.first] && ans[a.first] == -1)
                    ans[a.first] = j+1;
            }
        }
    }
}

//https://www.hackerrank.com/challenges/jim-and-his-lan-party

int main() {
    int n,m,q;
    cin>>n>>m>>q;
    for (int i = 0; i < n; ++i) { // Initialising
        parent[i] = i;
        ans[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        a--;
        count[a]++;
        arr[i][a] = 1;
    }
    for(auto a:count){
        if(a.second == 1)
            ans[a.first] = 0;
    }
    for (int j = 0; j < q; ++j) {
        int u,v;
        cin>>u>>v;
        u--;v--;
        unionset(u,v,j);
    }
    for (int i = 0; i < m; ++i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}