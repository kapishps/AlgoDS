#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = INFINITY;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

ll coins1(int a[],int n,int change){
    //1st Method (mine)
    sort(a,a+n);
    ll dp[n+1][change+1];
    for (int i = 0; i <=change; ++i) {
        dp[0][i] = inf;
    }
    dp[0][0]=0;
    for (int i = 1; i <=n; ++i) {
        for (int j = 0; j <= change; ++j) {
            dp[i][j] = min(dp[i-1][j], (j/a[i-1]) + dp[i-1][j%a[i-1]]);
        }
    }
    return dp[n][change];
}

ll coins2(int a[],int n,int change){
    //2nd space optimised method
    sort(a,a+n);
    ll dp[change+1];
    for (int i = 0; i <=change; ++i) {
        dp[i] = inf;
    }
    dp[0]=0;
    for (int i = 1; i <=change; ++i) {
        for (int j = 0; j < n; ++j) {
            if(a[j]<=i){
                dp[i] = min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    return dp[change];
}

int main() {
//    Boost;
    int change,n;
    cin>>change>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<coins1(a,n,change)<<"\n";
    cout<<coins2(a,n,change)<<"\n";
    return 0;
}