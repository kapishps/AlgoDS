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

int findset(int x) {
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y){
    int px = findset(x), py = findset(y);
    if(px!=py){
        if (rnk[px] > rnk[py]){
            parent[py]=px;
            rnk[px]+=rnk[py];
        }
        else{
            parent[px]= py;
            rnk[py]+=rnk[px];
        }
    }
}

void initialiseset(int start, int end){
    for (int i = start; i<=end; ++i) {
        parent[i]=i;
        rnk[i]=1;
    }
}

//https://www.hackerrank.com/challenges/merging-communities

int main() {
    Boost;
    int n,q;
    cin>>n>>q;

    initialiseset(0,n);

    for (int i = 0; i < q; ++i) {
        char c;
        cin>>c;
        if(c=='M'){
            int a,b;
            cin>>a>>b;
            unionset(a,b);
        }
        else{
            int a;
            cin>>a;
            cout<<rnk[findset(a)]<<"\n";
        }
    }
    return 0;
}