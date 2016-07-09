#include <iostream>
#include <set>
#include <vector>

using namespace std;

int parent[100001],rnk[100001];

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px = findset(x),py = findset(y);
    if(px!=py){
        if (rnk[px] > rnk[py]){
            parent[py] = px;
            rnk[px]+=rnk[py];
        }
        else{
            parent[px] = py;
            rnk[py]+=rnk[px];
        }
    }
}

//https://www.hackerrank.com/challenges/jim-and-his-lan-party

int main() {
    int n,m,q;
    cin>>n>>m>>q;
    int arr[n];
    vector<int> ans,game[m];
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        arr[i]=a;
        game[a].push_back(i);
        parent[i]=i;
        rnk[i]=1;
    }
    for (int i = 0; i < m; ++i) {
        if(game[i].size()==1)
            ans.push_back(0);
        else
            ans.push_back(-1);
    }
    for (int j = 0; j < q; ++j) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        unionset(a,b);

    }
    return 0;
}