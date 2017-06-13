#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e3+9;

ll a[MAXN][MAXN],Grid[MAXN][MAXN];
bitset<10000010> prime;
vector<pii> v;


void SieveOfEratosthenes(ll n) {
    prime.set();
    prime[0] = prime[1] = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * 2; j <= n; j += i)
                prime[j] = 0;
        }
    }
}

bool solve(int i,int j,int n,int m){
    if(i>n || j>m || Grid[i][j]==-1)
        return 0;
    if(i==n && j==m){
//        cout<<i<<" "<<j<<"\n";
        v.push_back(make_pair(i,j));
        return 1;
    }
    if(a[i][j]==-1)
        return 0;
    if(solve(i+1,j+1,n,m)){
        v.push_back(make_pair(i,j));
        return 1;
    }
    else if(solve(i+1,j,n,m)){
        v.push_back(make_pair(i,j));
        return 1;
    }
    else if(solve(i,j+1,n,m)){
        v.push_back(make_pair(i,j));
        return 1;
    }
    a[i][j]=-1;
    return 0;
}

int main() {
    FastIO;
    SieveOfEratosthenes(100000);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (!prime[a[i][j]])
                Grid[i][j] = -1;
            else
                Grid[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (Grid[i][1] == 0)
            Grid[i][1] = 1LL;
        else
            break;
    }
    for (int i = 2; i <= m; ++i) {
        if (Grid[1][i] == 0)
            Grid[1][i] = 1LL;
        else
            break;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            if (Grid[i][j] == -1)
                continue;
            if (Grid[i - 1][j] > 0)
                Grid[i][j] = (Grid[i][j] + Grid[i - 1][j] + MOD) % MOD;
            if (Grid[i][j - 1] > 0)
                Grid[i][j] = (Grid[i][j] + Grid[i][j - 1] + MOD) % MOD;
            if (Grid[i - 1][j - 1] > 0)
                Grid[i][j] = (Grid[i][j] + Grid[i - 1][j - 1] + MOD) % MOD;
        }
    }
    if(Grid[n][m]<0)
        cout<<-1;
    else {
        cout<<Grid[n][m]<<"\n";
        for (int i = 0; i <= n+1; ++i) {
            for (int j = 0; j <= m+1; ++j) {
                a[i][j] = 0;
            }
        }
        for (int i = 0; i <= n+1; ++i) {
            Grid[i][m+1] =-1;
        }
        for (int i = 0; i <= m+1; ++i) {
            Grid[n+1][i] = -1;
        }
        solve(1,1,n, m);
        for (int j = v.size()-1; j >=0; j--) {
            cout<<v[j].first<<" "<<v[j].second<<"\n";
        }
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout<<Grid[i+1][j+1]<<" ";
//        }
//        cout<<"\n";
//    }
    return 0;
}