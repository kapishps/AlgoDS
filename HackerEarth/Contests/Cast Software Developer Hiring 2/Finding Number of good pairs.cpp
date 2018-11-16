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

ll arr[MAXN];


int main() {
    FastIO;
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        arr[i] -= i;
    }

    map<ll,ll> M;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(M[-arr[i]] > 0)
            ans += M[-arr[i]];
        M[arr[i]]++;
    }
    cout<<ans;
}