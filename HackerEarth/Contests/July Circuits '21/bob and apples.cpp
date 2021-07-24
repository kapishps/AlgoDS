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
const int MAXN = 1e3+9;

int arr[MAXN][MAXN][2];
int p[MAXN], v[MAXN];

int knapsack(int n, int m, int h){
    if(n == 0 || m == 0){
        return 0;
    }
    if(arr[n][m][h] != -1)
        return arr[n][m][h];
    if(h == 1){
        if(p[n-1] > m)
            return arr[n][m][h] = knapsack(n-1, m, h);
        return arr[n][m][h] = max(v[n-1]+ knapsack(n-1, m - p[n-1], h), knapsack(n-1, m, h));
    }
    else {
        if(p[n-1] > 2*m){
            return arr[n][m][h] = knapsack(n-1, m, h);
        }
        if(p[n-1] > m){
            return arr[n][m][h] = max(v[n-1] + knapsack(n-1, m - (p[n-1]/2), h+1), knapsack(n-1, m, h));
        }
        return arr[n][m][h] = max(v[n-1] + knapsack(n-1, m - p[n-1], h), max(v[n-1] + knapsack(n-1, m - (p[n-1]/2), h+1), knapsack(n-1, m, h)));
    }
}

int main() {
    FastIO;
    int t,n,m;
    cin>>t;
    while(t){
        cin>>n>>m;
        for(int i = 0; i<=n; i++){
            for(int j=0; j<=m; j++){
                arr[i][j][0] = -1;
                arr[i][j][1] = -1;
            }
        }
        t--;
        for(int i=0;i<n;i++){
            cin>>v[i]>>p[i];
        }
        cout<<knapsack(n,m,0)<<"\n";
    }

}