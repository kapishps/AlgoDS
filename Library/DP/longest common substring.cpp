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
const int MAXN = 1e5+9;

int dp[110][110];

void solve(string a, string b, int n, int m){
    int result=0,index=0;
    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=m; ++j) {
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > result){
                    result = dp[i][j];
                    index = i;
                }
            }
            else
                dp[i][j] = 0;
        }
    }
    cout<<a.substr(index-result,result);
}

int main() {
//    Boost;
    string s1,s2;
    s1="12341";
    s2="341213";
//    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    solve(s1, s2, n, m);
    return 0;
}