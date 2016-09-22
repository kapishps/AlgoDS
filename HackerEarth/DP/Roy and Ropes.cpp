#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = INFINITY;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;
vector<ll> dp(MAXN);
int a[MAXN],b[MAXN];

int main() {
    Boost;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i = 0; i < n-1; ++i) {
            cin>>a[i];
        }
        for (int i = 0; i < n-1; ++i) {
            cin>>b[i];
        }
        for (ll i = 0; i <=n; i++) {
            if(i<2)
                dp[i]=i;
            else
                dp[i]= max(dp[i-1],max(i,i-1+max(a[i-2],b[i-2])));
//            cout<<dp[i]<<" ";
        }
        cout<<dp[n]<<"\n";
    }
}