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
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        string c;
        cin>>c;
        ll ans = 0;
        for(int i =0; i< 16; i++){
            if(c == "L"){
                if((1<<i)&n)
                    ans |= (1<<((i+16+m)%16));
            }
            else{
                if((1<<i)&n)
                    ans |= (1<<((i+16-m)%16));
            }
        }
        cout<<ans<<"\n";
    }
}