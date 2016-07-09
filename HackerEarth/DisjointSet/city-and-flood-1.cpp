#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int parent[100001],rnk[100001];

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    x = findset(x), y = findset(y);
    if (rnk[x] > rnk[y])
        parent[y] = x;
    else
        parent[x] = y;
    if (rnk[x] == rnk[y])
        rnk[y]++;
}

//https://www.hackerearth.com/problem/algorithm/city-and-flood-1/

int main() {
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        parent[i]=i;
        rnk[i]=0;
    }
    for (int i = 0; i < k; ++i) {
        int a,b;
        cin>>a>>b;
        unionset(a,b);
    }
    map <int,int> m;
    for (int i = 0; i < n; ++i) {
        findset(i);
        m[parent[i]]++;
    }
    cout<<m.size();
    return 0;
}