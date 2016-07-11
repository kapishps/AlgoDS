#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int parent[100001],rnk[100001];
set<pair<int,int> > s;
set<pair<int,int> > :: iterator it;

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

//https://www.hackerrank.com/challenges/components-in-graph

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    for (int i = 1; i<=2*n; ++i) {
        parent[i]=i;
        rnk[i]=-1;
    }
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        if(rnk[findset(a)]<0){
            s.insert(make_pair(1,a));
            rnk[a]=1;
        }
        if(rnk[findset(b)]<0){
            s.insert(make_pair(1,b));
            rnk[b]=1;
        }
        unionset(a,b);
    }
    int sm,l;
    it=s.begin();
    sm=it->first;
    it=s.end();
    it--;
    l=it->first;
    cout<<sm<<" "<<l;
    return 0;
}
