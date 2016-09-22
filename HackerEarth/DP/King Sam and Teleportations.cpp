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

ll dp[26][MAXN];

void solve(string s){
    for (int k = 0; k < 26; ++k) {
        dp[k][0]=1;
        map<int,ll> map1;
        map1[s[0]-'a']=1;
        for (int i = 1; i < s.size(); ++i) {
            int val=(s[i]-'a')-k;
            if(val<0)
                val+=26;
            dp[k][i] = map1[val];
            if(s[i-1]-'a'!=val){
                dp[k][i]=(dp[k][i]+dp[k][i-1])%MOD;
            }
            map1[s[i]-'a'] = (map1[s[i]-'a'] + dp[k][i])%MOD;
        }
    }
}

//https://www.hackerearth.com/practice/algorithms/dynamic-programming/
// introduction-to-dynamic-programming-1/practice-problems/algorithm/game-of-strings-44/

int main() {
    Boost;
    string s;
    cin>>s;
    int t;
    cin>>t;
    solve(s);
//    endl instead of "\n" gives timeout in all test cases.
    while (t--){
        int k;
        cin>>k;
        cout<<dp[k%26][s.size()-1]<<"\n";
    }
}
