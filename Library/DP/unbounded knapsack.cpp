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

ll solve(int a[],int n,int k){
    ll dp[n+1][k+1];
    for (int i = 0; i <=k; ++i) {
        dp[0][i]=0;
    }
    for (int i = 1; i <=n; ++i) {
        for (int j = 0; j <=k; ++j) {
            if(j>=a[i-1])
                dp[i][j] = max(dp[i-1][j], dp[i][j-a[i-1]] + a[i-1]);
            else
                dp[i][j] = dp[i-1][j];
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    return dp[n][k];
}

//https://www.hackerrank.com/challenges/unbounded-knapsack

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        cout<<solve(a,n,k)<<endl;
    }
    return 0;
}
