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
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int MOD=1e9+7;
const int MAXN=1e6+5;

int main() {
    Boost;
    int t;
    cin>>t;
    vector<ll> dp(MAXN);
    while(t--){
        string s;
        cin>>s;
        ll ans=0;
        dp.assign(s.size()+1,0);
        for (int i = 3; i <=s.size(); ++i) {
            if(s[i-1]==s[i-3] && s[i-2]==s[i-3])
                dp[i]=0;
            else
                dp[i]=dp[i-3]+3;
            ans = max(ans,dp[i]);
        }
        cout<<s.size()-ans<<"\n";
    }
}
