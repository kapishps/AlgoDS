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

ll solve(int a[],int n){
    ll dp[n];
    for (int i = 0; i < n; ++i) {
        dp[i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(a[j]<a[i])
                dp[i] = max(dp[i],dp[j] + a[i]);
        }
    }
    ll ans=0;
    for (int i = 0; i < n; ++i) {
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main() {
    Boost;
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    cout<<solve(a,n);
//    Input:
//    7
//    1 101 2 3 100 4 5
//    Output:
//    106
    return 0;
}