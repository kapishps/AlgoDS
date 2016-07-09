#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

multiset<pair<int,int> >s;
multiset<pair<int,int> > :: iterator it,it1;
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

//https://www.hackerearth.com/problem/algorithm/city-and-campers-2/

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
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
            int min = INT_MAX;
            it = s.begin();
            it1 = ++(s.begin());
            for( ;it1!=s.end();it++,it1++){
                if( (it1->first) - (it->first) <min)
                    min = (it1->first) - (it->first);
                if(min == 0 )
                    break;
            }
            cout<<min<<endl;
        }
        else
            cout<<"0"<<endl;
    }
    return 0;
}