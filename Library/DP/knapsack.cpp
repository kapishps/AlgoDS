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
const int MAXN = 2e3+9;

ll wt[MAXN],val[MAXN];
ll dp[MAXN][MAXN]={0};

ll solve(int n,int k){
    for (int i = 1; i <=n; ++i) {
        for (int j = 0; j <=k; ++j) {
            if(wt[i-1]<=j)
                dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}

//http://www.spoj.com/problems/KNAPSACK/

int main() {
    Boost;
    int n,k;
    cin>>k>>n;
    for (int i = 0; i < n; ++i) {
        cin>>wt[i]>>val[i];
    }
    cout<<solve(n,k);
    return 0;
}