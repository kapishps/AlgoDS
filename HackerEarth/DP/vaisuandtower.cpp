#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

int a[MAXN];
int dp[MAXN][2];

int solve(int n,int idx,int prev){          //0~-1 && 1~1 for prev
    if(idx==0){                           //1st number
        if(a[idx]>0)
            return 1+solve(n,idx+1,0);
        else
            return solve(n,idx+1,0);
    }
    else if(idx==n-1){                    //last number
        if(a[idx]>0)
            return 0;
        else
            return 1;
    }
    else{
        if(dp[idx][prev]!=-1)
            return dp[idx][prev];

        if(a[idx]>0){
            if(prev>0)
                return dp[idx][prev]=solve(n,idx+1,prev);
            else
                return dp[idx][prev]=min(1+solve(n,idx+1,0),solve(n,idx+1,1));
        }
        else{
            if(prev>0)
                return dp[idx][prev]=1+solve(n,idx+1,prev);
            else
                return dp[idx][prev]=min(solve(n,idx+1,0),1+solve(n,idx+1,1));
        }
    }
}

//https://www.hackerearth.com/problem/algorithm/vaishu-and-tower-arrangements/

int main() {
    Boost;
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        cout<<solve(n,0,0)<<"\n";
    }
    return 0;
}