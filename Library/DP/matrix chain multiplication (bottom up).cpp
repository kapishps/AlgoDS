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

ll a[110],dp[110][110],path[110][110];

ll solve(int start, int end){       //start=i & end=j
    if(start==end)
        return 0;
    if(dp[start][end]>0)
        return dp[start][end];
    ll result = inf;
    for (int k = start; k < end; ++k) {
        ll curr = solve(start,k) + solve(k+1,end) + a[start-1]*a[k]*a[end];

        if(curr < result){
            result = curr;
            path[start][end] = k;
        }
    }
    dp[start][end] = result;
    return result;
}

void tracePath(int i ,int j , int n) {
    int k=path[i][j];
    if(i==j)
        cout<<"A"<<i;
    else {
        cout<<"(";
        tracePath(i , k , n);
        cout<<" * ";
        tracePath(k+1 , j , n);
        cout<<")";
    }
}

int main() {
//    Boost;
    int n;       //no. of matrices
    cout<<"Enter no. of Matrices : ";
    cin>>n;
    for (int i = 0; i <=n; ++i) {
        cin>>a[i];
    }
    cout<<"Minimum cost is : "<<solve(1,n)<<"\n";
//    for(int i=1;i<=n;i++)  {
//        for(int j=1;j<=n;j++) {
//            printf("%d\t\t",path[i][j]);
//        } printf("\n");
//    }
    tracePath(1,n,n);
    return 0;
}