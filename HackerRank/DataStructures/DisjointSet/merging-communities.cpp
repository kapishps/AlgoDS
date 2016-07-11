#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
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
    if (rnk[x] > rnk[y]){
        parent[y]=x;
        rnk[x]+=rnk[y];
    }
    else{
        parent[x]= y;
        rnk[y]+=rnk[x];
    }
}

//https://www.hackerrank.com/challenges/merging-communities

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    cin>>n>>q;
    for (int i = 0; i <=n; ++i) {
        parent[i]=i;
        rnk[i]=1;
    }
    for (int i = 0; i < q; ++i) {
        char c;
        cin>>c;
        if(c=='M'){
            int a,b;
            cin>>a>>b;
            if(findset(a)!=findset(b))
                unionset(a,b);
        }
        else{
            int a;
            cin>>a;
            cout<<rnk[findset(a)]<<endl;
        }
    }
    return 0;
}
