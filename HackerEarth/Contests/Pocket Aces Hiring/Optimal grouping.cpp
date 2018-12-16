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

int a[509],sml[509][509];
int n;
int M[509][509];


int solve(int i, int k){
    if(i == 0){
        if(k == 0)
            return 0;
        return -inf;
    }
    if(k > i)
        return -inf;

    if(M[i][k] != -1)
        return M[i][k];

    int ans = 0;
    for (int j = i-1; j >=0; --j) {
        ans = max(solve(j, k - 1) + sml[j + 1][i], ans);
    }
    return M[i][k] = ans;
}



int main() {
    FastIO;
    int k;
    cin>>n>>k;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }

    for (int i = n; i > 0; --i) {
        for (int j = i-1; j > 0; --j) {
            sml[j][i] = sml[j+1][i];
            if(a[j] > a[i])
                sml[j][i]++;
        }
    }


    for (int i = 1; i <=n; ++i) {
        for (int j = i+1; j <=n; ++j) {
            sml[i][j] += sml[i][j - 1];
        }
    }

    memset(M,-1,sizeof(M));

    cout<<solve(n,k);
    return 0;
}