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
    ll x,n;
    cin>>x>>n;
    if(n >= 10){
        cout<<1;
    }
    else{
        ll fact = 1;
        while(n > 1){
            fact *= n;
            fact %= 10;
            n--;
        }
        cerr<<"factorial ="<<fact<<" ";
        ll ans = 1;
        while(fact >= 1){
            ans *= x;
            ans %= 10;
            fact--;
        }
        cout<<ans%10;
    }
    return 0;
}