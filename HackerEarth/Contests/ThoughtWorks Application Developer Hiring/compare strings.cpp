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

int a[MAXN],b[MAXN];


int main() {
    FastIO;
    int n,t;
    cin>>n>>t;
    string A,B;
    cin>>A>>B;
    for (int i = 1; i <=n; ++i) {
        a[i]=A[i-1]-'0';
        b[i]=B[i-1]-'0';
    }

    int idx = n+1;
    string ans = "NO";
    set<int> s;
    for (int i = 1; i <=n; ++i) {
        if(a[i]==1)
            s.insert(i);
        if(a[i]==b[i])
            continue;
        if(a[i]==1 && b[i]==0)
            idx = min(idx,i-1);
    }
    if(idx==n+1)
        ans = "YES";
    while(t--){
        int x;
        cin >> x;
        if(ans=="NO" && !s.empty())
            s.erase(x);
        if((b[x] == 0 && x<=idx) || s.empty())
            ans = "YES";
        cout<<ans<<"\n";
    }

    return 0;
}