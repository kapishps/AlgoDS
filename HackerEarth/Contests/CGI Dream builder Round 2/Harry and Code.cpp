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
const int MAXN = 1e6+9;

ll a[MAXN];

ll solve(int n){
    ll cnt=0;
    for (int i = 0; i < n; ++i) {
        ll g=0,s=0;
        for (int j = i+1; j < n; ++j) {
            if(a[i]>a[j])
                g++;
        }
        for (int j = i-1; j >=0; j--) {
            if(a[i]>a[j])
                s++;
        }
        cnt +=s*g;
    }
    return cnt;
}

// 52/100

int main() {
    FastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout<<solve(n);
}