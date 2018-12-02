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
    int n,h;
    cin>>n>>h;
    int w[n],l[n];
    for (int i = 0; i < n; ++i) {
        cin>>w[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>l[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = w[i] - (l[i]/4.0);
        if(l[i]%4 == 0){
            ans = max(ans, x);
        }
        else{
            ans = max(ans, x+1);
        }
    }
    cout<<max(ans-h,0);

}