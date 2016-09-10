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

ll dp[MAXN][MAXN]={0};

ll knapsack(int wt[],int cost[],int n,int k){
    for (int i = 1; i <=n; ++i) {
        for (int j = 0; j <=k; ++j) {
            if(wt[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], cost[i-1]+ dp[i-1][j-wt[i-1]]);
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    return dp[n][k];
}

//0/1 knapsack problem

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int wt[n],cost[n];
    for (int i = 0; i < n; ++i) {
        cin>> wt[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>cost[i];
    }
    cout<<knapsack(wt,cost,n,k);
    return 0;
}
