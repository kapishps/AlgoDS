#include <iostream>
#include <algorithm>
using namespace std;

int parent[1001],rnk[1001];
int mod=1000000007;

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    x = findset(x), y = findset(y);
    if (rnk[x] < rnk[y])
        parent[y] = x;
    else
        parent[x] = y;
    //if (rnk[x] == rnk[y])
    //   rnk[y]++;
}

//https://www.hackerearth.com/problem/algorithm/city-and-fireman-vincent/

int main() {
    int n,k;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin>>a;
        parent[i]=i;
        rnk[i]=a;
    }
    cin>>k;
    for (int i = 0; i < k; ++i) {
        int a,b;
        cin>>a>>b;
        unionset(a-1,b-1);
    }
    int hash[1001]={0};
    for(int i=0;i<n;i++){
        findset(i);
        if(rnk[i]==rnk[parent[i]])
            hash[parent[i]]++;
    }
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        if(hash[i]>1)
            result=(result*hash[i])%mod;
    }
    cout<<result;
    return 0;
}