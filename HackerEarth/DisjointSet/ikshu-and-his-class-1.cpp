#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<pair<int,int> >s;
set<pair<int,int> > :: iterator it;
int parent[100001],rnk[100001];
int mod=1000000007;

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px = findset(x),py = findset(y);
    if(px!=py){
        s.erase(make_pair(rnk[px],px));
        s.erase(make_pair(rnk[py],py));
        if (rnk[px] > rnk[py]){
            parent[py] = px;
            rnk[px]+=rnk[py];
            s.insert(make_pair(rnk[px],px));
        }
        else{
            parent[px] = py;
            rnk[py]+=rnk[px];
            s.insert(make_pair(rnk[py],py));
        }
    }
}

long long factorial(int x){
    if(x==1)
        return 1;
    else
        return (x*factorial(x-1))%mod;
}

//https://www.hackerearth.com/problem/algorithm/ikshu-and-his-class-1/

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) {
        parent[i] = i;
        rnk[i]=1;
        s.insert(make_pair(1,i));
    }
    for (int i = 0; i < q; ++i) {
        int a,b;
        cin>>a>>b;
        unionset(a,b);
    }
    long long result=1;
    for (it=s.begin();it!=s.end(); it++) {
        if(it->first > 1)
            result=(result*factorial(it->first))%mod;
    }
    cout<<result;
    return 0;
}