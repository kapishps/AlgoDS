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

int main() {
    FastIO;
    ll n;
    cin>>n;
    if(n > 3)
        cout<<(((n*n) - 1)*((n*n) - 3))/48;
    else{
        int a[] = {0,0,1};
        cout<<a[n-1];
    }
    return 0;
}