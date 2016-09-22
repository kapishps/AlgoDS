#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = INFINITY;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

int main() {
//    clock_t tStart = clock();
//    Boost;
    int t;
    cin>>t;
    vector<ll> dp(MAXN);
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        dp.assign(n+1,0);
        for(int i=1;i<=n;i++){
            if(i==1)
                dp[i]=a[0];
            else
                dp[i]=max(dp[i-1],dp[i-2]+a[i-1]);
        }
        cout<<dp[n]<<"\n";
    }
//    cout<<endl;
//    cout<<(double)(clock() - tStart)/CLOCKS_PER_SEC;
}
