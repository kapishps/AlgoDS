#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

int parent[MAXN],rnk[MAXN];
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

void initialiseset(int start, int end){
    for (int i = start; i<=end; ++i) {
        parent[i]=i;
        rnk[i]=1;
        s.insert(make_pair(1,i));
    }
}

//https://www.hackerrank.com/challenges/components-in-graph

int main() {
    Boost;
    int n;
    cin>>n;

    initialiseset(1,2*n);

    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        unionset(a,b);
    }
    int smallest=1,largest;
    it=s.begin();
    while(smallest==1)
        smallest = (*(++it)).first;
    it=s.end();
    largest = (--it)->first;
    cout<<smallest<<" "<<largest;
    return 0;
}