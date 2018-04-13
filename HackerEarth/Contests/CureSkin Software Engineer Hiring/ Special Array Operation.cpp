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

ll a[MAXN],ans[MAXN];


int main() {
    FastIO;
    int n,q;
    cin>>n>>q;

    priority_queue<ll,vector<ll>> ax;
    priority_queue<ll,vector<ll>,greater<ll>> in;

    ll sum=0;

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        ax.push(a[i]);
        in.push(a[i]);
        sum+=a[i];
    }
    ans[0] = sum;
    for (int i = 1; i <= n; ++i) {
        ll t = ax.top() - in.top();
        ans[i] = ans[i-1]- ax.top() - in.top() + t;
        ax.pop();
        in.pop();
        ax.push(t);
        in.push(t);
    }

    for (int i = 0; i < q; ++i) {
        int x;
        cin>>x;
        cout<<ans[x]<<"\n";
    }

    return 0;
}