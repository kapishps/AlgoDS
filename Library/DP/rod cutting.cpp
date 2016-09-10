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
#define pb push_back
#define mp make_pair

const int MOD=1e9+7;
const int MAXN=1e6+5;

ll solve(int a[],int n){
    ll dp[n+1];
    for (int i = 0; i < n + 1; ++i) {
        dp[i]=0;
    }
    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=i; ++j) {
            dp[i]=max(dp[i],dp[i-j]+a[j-1]);
        }
    }
    return dp[n];
}

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        cout<<solve(a,n)<<endl;
    }
    return 0;
}
