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

//https://www.hackerrank.com/challenges/sherlock-and-cost

int main() {
    Boost;
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int b[n];
        for (int i = 0; i < n; ++i) {
            cin>>b[i];
        }
        int dp[n][2];
        dp[0][0]=0;
        dp[0][1]=0;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(abs(1-b[i-1])+dp[i-1][1],    //b[i]=1, b[i-1]=b[i-1]
                           dp[i-1][0]);                 //b[i]=1, b[i-1]=1
            dp[i][1] = max(abs(b[i]-1)+dp[i-1][0],      //b[i]=b[i], b[i-1]=1
                           abs(b[i]-b[i-1])+dp[i-1][1]);//b[i]=b[i], b[i-1]=b[i-1]
        }
        cout<<max(dp[n-1][0], dp[n-1][1])<<"\n";
    }
    return 0;
}