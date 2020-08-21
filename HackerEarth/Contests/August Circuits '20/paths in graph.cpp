#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

int n = 1;
vector<pii> edges;

int main() {
    FastIO;
    ll k;
    cin>>k;
    ll t = k;
    vector<int> bits;
    while(t){
        if(t%2 == 0){
            bits.push_back(0);
        }
        else{
            bits.push_back(1);
        }
        t /=2;
    }

    edges.push_back({n,n+1});
    n++;
    for(int i = bits.size() -2; i >= 0; i--){
        edges.push_back({n,n+1});
        edges.push_back({n,n+2});
        edges.push_back({n+1,n+3});
        edges.push_back({n+2,n+3});
        n += 3;
        if(bits[i] == 1){
            edges.push_back({1,n});
        }
    }

    cout<<n<<" "<<edges.size()<<"\n";
    for(int i = 0;i<edges.size();i++){
        cout<<edges[i].first<<" "<<edges[i].second<<"\n";
    }
}