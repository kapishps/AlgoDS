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
const int MAXN = 2e5+9;

ll a[MAXN],pow2[MAXN];

void calc_pow2(int n){
    pow2[0]=1;
    for (int i = 1; i < n; ++i) {
        pow2[i] =2*pow2[i-1];
        pow2[i] %=MOD;
    }
}

// 40/100

int main() {
    FastIO;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    calc_pow2(MAXN);
    sort(a,a+n);
    ll ans =0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ans += (a[i] | a[j])*pow2[j-i-1];
            ans %=MOD;
        }
    }
    cout<<ans;

}