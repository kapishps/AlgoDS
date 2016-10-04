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

int solve(int a[],int b[],int n){
    vector<pii > v;
    int dp[n];
    for (int i = 0; i < n; ++i) {
        v.pb(mp(a[i],b[i]));
        dp[i]=1;
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(v[i].second >= v[j].second)
                dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int ans=0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans,dp[i]);
    }
    return ans;
}

//http://www.spoj.com/problems/BRIDGE/

int main() {
    Boost;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin>>b[i];
        }
        cout<<solve(a,b,n)<<"\n";
    }
    return 0;
}