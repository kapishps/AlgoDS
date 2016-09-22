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
const int MAXN = 1e4+5;
vector<ll> dp(MAXN);
int a[MAXN];

int main() {
    Boost;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        dp[0]=0;
        for (int i = 1; i < n + 1; i++) {
            if (i <= k) {
                dp[i] = max(0, a[i - 1]);
                dp[i] = max(dp[i],dp[i-1]);
            }
            else
                dp[i] = max(dp[i-1], dp[i - k - 1] + a[i - 1]);
//                cout << dp[i] << " ";
        }
        cout<<dp[n]<<"\n";
    }
}
