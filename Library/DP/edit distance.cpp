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

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

int solve(string a,string b){
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    for (int i = 0; i <=n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <=m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=m; ++j) {
            if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
        }
    }
    return dp[n][m];
}

//http://www.spoj.com/problems/EDIST/

int main() {
    Boost;
    int t;
    cin>>t;
    while (t--){
        string a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<"\n";
    }
    return 0;
}