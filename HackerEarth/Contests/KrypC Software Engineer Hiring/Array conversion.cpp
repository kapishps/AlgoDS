#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

int a[109],dp[109][20009];

int solve(int i,int k){
    if(i == 0)
        return (a[i] == k-10000 || a[i] == -(k-10000) || a[i]-1 == k-10000 || a[i]+1 == -(k-10000));

    if(dp[i][k]!=-1)
        return dp[i][k];

    return dp[i][k] = (solve(i-1,k+a[i]) || solve(i-1,k-a[i]) || solve(i-1,k-a[i]-(i+1)) || solve(i-1,k-a[i]+(i+1)));
}



int main() {
    FastIO;
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>n>>k;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        memset(dp, -1, sizeof dp);
        if(solve(n-1,k+10000))
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }
    return 0;
}