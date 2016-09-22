#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int MOD=1e9+7;
const int MAXN=1e6+5;

int main() {
//    Boost;
    int n,q;
    cin>>n>>q;
    int a[n],b[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }
    ll dp[n+1][2];
    dp[0][0]=0;
    dp[0][1]=0;
    for (int i = 1; i <=n; ++i) {
        if(i%2==1){
            dp[i][0] = dp[i-1][0]+a[i-1];
            dp[i][1] = dp[i-1][1]+b[i-1];
        }
        else{
            dp[i][0] = dp[i-1][0]+b[i-1];
            dp[i][1] = dp[i-1][1]+a[i-1];
        }
    }
    while (q--){
        int t,r,l;
        cin>>t>>l>>r;
        if(t==1){
            if((l-1)%2==0)
                cout<<dp[r][0]-dp[l-1][0]<<"\n";
            else
                cout<<dp[r][1]-dp[l-1][1]<<"\n";
        }
        else{
            if((l-1)%2==0)
                cout<<dp[r][1]-dp[l-1][1]<<"\n";
            else
                cout<<dp[r][0]-dp[l-1][0]<<"\n";
        }
    }
}
