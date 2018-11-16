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

int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if(((x1==x2) && (y1==y2)) || ((x3==x4) && (y3==y4)))
            cout<<"INVALID"<<"\n";
        else if(((x2-x1)*(x4-x3)) == (-(y2-y1)*(y4-y3)))
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }
}