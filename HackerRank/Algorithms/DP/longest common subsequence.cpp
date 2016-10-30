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

void solve(int a[],int b[],int n,int m){

    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=m; ++j) {
            if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//            cout<<dp[i][j]<<" ";
        }
//        cout<<"\n";
    }
    int i=n,j=m;
    vector<int> v;
    while (i>0 && j>0){
        if(a[i-1]==b[j-1]){
            v.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(v.begin(),v.end());
    for(i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return;
}

//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence

int main() {
//    Boost;
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin>>b[j];
    }
    solve(a,b,n,m);
    return 0;
}