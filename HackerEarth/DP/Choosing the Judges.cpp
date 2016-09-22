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
int a[MAXN];

int main() {
//    Boost;
    int t;
    cin>>t;
    for (int k = 1; k <=t; ++k){
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        for (int i = 1; i <=n; i++) {
            if(i<=1)
                dp[i]=a[i-1];
            else
                dp[i]= max(dp[i-1],dp[i-2]+a[i-1]);
//            cout<<dp[i]<<" ";
        }
        cout<<"Case "<<k<<": "<<dp[n]<<"\n";
    }
}