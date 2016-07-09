#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<pair<int,int> >s;
set<pair<int,int> > :: iterator it;
int parent[100001],rnk[100001];

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

//https://www.hackerearth.com/problem/algorithm/city-and-campers/

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        parent[i] = i;
        rnk[i]=1;
        s.insert(make_pair(1,i));
    }
    for (int i = 0; i < q; ++i) {
        int a,b;
        cin>>a>>b;
        if(findset(a)!=findset(b))
            unionset(a,b);
        if(s.size()>1){
            it=s.begin();
            int x=it->first;
            it=s.end();
            it--;
            int y=it->first;
            cout<<y-x<<endl;
        }
        else
            cout<<"0"<<endl;
    }
    return 0;
}