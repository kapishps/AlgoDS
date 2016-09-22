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
const int MAXN=1e3+5;

ll solve(int a[][MAXN],int n,int m){
    ll dp[n+1][MAXN];
    for (int i = 0; i <=n; ++i) {
        dp[i][0]=1e9;
        dp[0][i]=1e9;
    }
    dp[0][0]=0;

    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=m; ++j) {
            dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + a[i-1][j-1];
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    return dp[n][m];
}

//Min Cost Path in a 2d grid

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n][MAXN];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>a[i][j];
        }
    }
//    int x,y;
//    cin>>x,y;
    cout<<solve(a,n,m);
    return 0;
}
