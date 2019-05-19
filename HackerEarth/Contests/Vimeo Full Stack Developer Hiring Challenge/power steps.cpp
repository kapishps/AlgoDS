#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

ll pow3[40];

void precalc(){
    pow3[0] = 1;
    for (int i = 1; i < 40; ++i) {
        pow3[i] = pow3[i-1]*3;
    }
}

int main() {
    FastIO;
    int t;
    cin>>t;
    precalc();
    while(t--){
        ll n,u,v;
        cin>>n>>u>>v;

        ll steps = 0, diff = abs(v- u);
        if(diff%3 != 0){
            cout<<-1<<"\n";
        }
        else{
            while(diff > 0){
                for (int i = 1; i < 40; ++i) {
                    if(pow3[i] > diff){
                        diff -= pow3[i-1];
                        steps += (i-1);
                        break;
                    }
                }
            }
            cout<<steps<<"\n";
        }
    }
    return 0;
}