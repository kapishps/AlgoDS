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
const int MAXN = 2e5+9;

ll a[MAXN];

int main() {
    FastIO;
    int n;
    cin>>n;
    ll x =0, y=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    if(n%2 == 1){
        x += a[(n/2)];
        for (int i = (n/2)-1,j=n/2+1; i >=0 && j<n; --i,++j) {
            x += min(a[i],a[j]);
            y += max(a[j],a[i]);
        }
    }
    else{
        for (int i = (n/2)-1,j=n/2; i >=0 && j<n; --i,++j) {
            x += max(a[i],a[j]);
            y += min(a[j],a[i]);
        }
    }

    if(x >= y)
        cout<<"Alex "<<(x-y)<<"\n";
    else
        cout<<"Bob "<<(y-x)<<"\n";

}