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

int steps(int n){
    int count=0;
    while(n){
        if(n>=5){
            count+=n/5;
            n=n%5;
            continue;
        }
        if(n>=2){
            count+=n/2;
            n=n%2;
            continue;
        }
        count++;
        n--;
    }
    return count;
}

ll solve(int a[],int n,int smallest){
    ll dp[5][n+1];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <=n; ++j) {
            if(j==0)
                dp[i][j]=0;
            else
                dp[i][j] = dp[i][j-1] + steps(a[j-1]-smallest+i);
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    return min(dp[0][n],min(dp[1][n],min(dp[2][n],min(dp[3][n],dp[4][n]))));
}

//https://www.hackerrank.com/challenges/equal

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a[n],smallest=1e9;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            smallest = min(smallest,a[i]);
        }
        cout<<solve(a,n,smallest)<<endl;
    }
    return 0;
}
