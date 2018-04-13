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

int a[MAXN];

int main() {
    FastIO;
    int n,q;
    cin>>n>>q;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        a[i] = __builtin_popcount(a[i]);
    }
    while(q--){
        int k;
        cin>>k;
        int i=0,j=0;
        int ans=inf,curr=a[j];
        while(i<=j && j<n){
            if(curr < k){
                curr +=a[++j];
            }
            else{
                ans = min(ans,j-i+1);
                curr -=a[i];
                i++;
            }
        }
        if(ans==inf)
            cout<<-1<<"\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}