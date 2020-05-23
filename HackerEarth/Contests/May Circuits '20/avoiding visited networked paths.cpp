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

ll prod[MAXN][MAXN], tot[MAXN][MAXN][2][3][3];
int a,b,c;

void solve(ll val){
    a = 0, b = 0, c = 0;
    if(val%5 == 0)
        a++;
    if(val%3 == 0)
        b++;
    if(val%9 == 0)
        b++;
    if(val%2 == 0)
        c++;
    if(val%4 == 0)
        c++;
}

int main() {
    FastIO;
    ll n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>x;
            prod[i][j] = 1;

            if(x%107 == 0 || x%1361 == 0 || x%10000019 == 0){
                while(x%107 == 0){
                    prod[i][j] *= 2;
                    x /= 107;
                }
                while(x%1361 == 0){
                    prod[i][j] *= 3;
                    x /= 1361;
                }
                while(x%10000019 == 0){
                    prod[i][j] *= 5;
                    x /= 10000019;
                }
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<prod[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";

    ll sum = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum = 0;
            solve(prod[i][j]);
            if(i==1 && j==1){
                tot[i][j][a][b][c] = 1;
            }
            for(int x =0; x<2;x++){
                for(int y =0; y<3;y++){
                    for(int z=0;z<3;z++){
                        tot[i][j][min(x+a,1)][min(y+b,2)][min(z+c,2)] += tot[i-1][j][x][y][z];
                        tot[i][j][min(x+a,1)][min(y+b,2)][min(z+c,2)] += tot[i][j-1][x][y][z];
                        tot[i][j][min(x+a,1)][min(y+b,2)][min(z+c,2)] %= MOD;
                        sum += tot[i][j][x][y][z];
                        sum %= MOD;
                    }
                }
            }
        }
    }
    
    // for(int x =0; x<2;x++){
    //     for(int y =0; y<3;y++){
    //         for(int z=0;z<3;z++){
    //             cout<<tot[n][m][x][y][z]<<"\n";
    //         }
    //     }
    // }

    cout<<(sum - tot[n][m][1][2][2] + MOD)%MOD;

}