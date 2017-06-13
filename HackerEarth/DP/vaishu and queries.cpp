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


map<int,int> map1;
int dp[101][101][101];
int cnt[MAXN][2];

int solve(int r,int b,int idx) {
    if (idx == 0) {
        if (r >= cnt[0][0] && b >= cnt[0][1])
            return 1;
        return 0;
    }

    if (dp[r][b][idx])
        return dp[r][b][idx];

    if (r >= cnt[idx][0] && b >= cnt[idx][1])
        return dp[r][b][idx] = max(1 + solve(r - cnt[idx][0], b - cnt[idx][1], idx - 1), solve(r, b, idx - 1));
    return dp[r][b][idx] = solve(r, b, idx - 1);
}

//https://www.hackerearth.com/problem/algorithm/vaishu-and-queries/

int main() {
    Boost;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        map1.clear();
        for (int j = 0; j < s.size(); ++j) {
            map1[s[j]]++;
        }
        cnt[i][0]=map1['R'];
        cnt[i][1]=map1['B'];
    }
    int q;
    cin>>q;
    while (q--){
        int x,y;
        cin>>x>>y;
        cout<<solve(x,y,n-1)<<"\n";
    }
    return 0;
}