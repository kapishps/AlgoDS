#include <iostream>
#include <map>

using namespace std;

const int MOD = 1000000007;

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

//https://www.hackerrank.com/challenges/kundu-and-tree

int main() {
    int n;
    cin>>n;
    for (int i = 1; i <=n; ++i) {
        parent[i]=i;
        rnk[i]=1;
    }
    for (int i = 0; i<n-1; ++i) {
        int a,b;
        char c;
        cin>>a>>b>>c;
        if(c=='b'){
            unionset(a,b);
        }
    }
    map <int,int> m;
    map <int ,int > ::iterator a;
    for (int i = 1; i <=n; ++i) {
        findset(i);
        m[parent[i]]++;
    }
    long long ans=0,sum=0,prod=0;
    for (a = m.begin(); a !=m.end() ; ++a) {
        ans = (ans + (prod*a->second))%MOD;
        prod = (prod + (sum*a->second))%MOD;
        sum = (sum + a->second)%MOD;
    }
    cout<<ans;
    return 0;
}