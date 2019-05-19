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
const int MAXN = 1e6+9;

int a[MAXN];

int main() {
    FastIO;
    int n,q;
    cin>>n>>q;

    int i = 1;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x == 2){
            a[y] = i;
            i++;
        }
        else{
            int ans = 0;
            while(y){
                ans = max(a[y], ans);
                y /= 2;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}