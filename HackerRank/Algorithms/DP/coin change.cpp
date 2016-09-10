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

long long coins(int a[],int n,int change){
    ll dp[n+1][change+1];
    for (int i = 0; i <=n; ++i) {
        for (int j = 0; j <=change; ++j) {
            if(j==0)
                dp[i][j]=1;
            else
                dp[i][j]=0;
        }
    }

    for (int i = 1; i <=n; ++i) {
        for (int j = 0; j <=change; ++j) {
            if(j-a[i-1]>=0)
                dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
//    for (int i = 0; i <=n; ++i) {
//        for (int j = 0; j <=change; ++j) {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[n][change];
}

//https://www.hackerrank.com/challenges/coin-change

int main() {
    int change,n;
    cin>>change>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<coins(a,n,change);
    return 0;
}
