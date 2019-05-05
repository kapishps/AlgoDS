#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

char a[109][109];

int solve(int n, int m) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(i >= 3 && j < m-3){
                if (a[i][j] == 's' && a[i - 1][j + 1] == 'a' && a[i - 2][j + 2] == 'b' && a[i - 3][j + 3] == 'a')
                    ans++;
            }
            if(i < n-3 && j < m-3){
                if (a[i][j] == 's' && a[i + 1][j + 1] == 'a' && a[i + 2][j + 2] == 'b' && a[i + 3][j + 3] == 'a')
                    ans++;
            }
            if(i < n-3){
                if (a[i][j] == 's' && a[i + 1][j] == 'a' && a[i + 2][j] == 'b' && a[i + 3][j] == 'a')
                    ans++;
            }
            if(j < m-3){
                if (a[i][j] == 's' && a[i][j + 1] == 'a' && a[i][j + 2] == 'b' && a[i][j + 3] == 'a')
                    ans++;
            }
        }
    }
    return ans;
}

int main() {
    FastIO;
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>a[i][j];
        }
    }
    cout<<solve(n,m);
    return 0;
}