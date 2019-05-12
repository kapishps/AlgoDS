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
const int MAXN = 1e5+9;

vector<int> a,b;

int main() {
    FastIO;
    int n,k;
    cin>>n>>k;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    while(k--){
        int Min = inf, idx = -1;
        for (int i = 0; i < a.size(); ++i) {
            if(i == 0 || i == a.size() - 1){
                if(i == 0 ){
                    Min = abs(a[i] - a[i+1]);
                    idx = i;
                }
                else{
                    if(abs(a[i] - a[i-1]) < Min) {
                        Min = abs(a[i] - a[i - 1]);
                        idx = i;
                    }
                }
            }
            else{
                if(-abs(a[i-1] - a[i+1]) + abs(a[i] - a[i+1]) + abs(a[i] - a[i-1]) < Min) {
                    Min = -abs(a[i-1] - a[i+1]) + abs(a[i] - a[i+1]) + abs(a[i] - a[i-1]);
                    idx = i;
                }
            }
        }

        vector<int> b;
        for (int i = 0; i < a.size(); ++i) {
            if(i == idx)
                continue;
            b.push_back(a[i]);
        }
        a = b;
    }

    ll ans = 0;
    for (int i = 1; i < a.size(); ++i) {
        ans += abs(a[i] - a[i-1]);
    }
    cout<<ans;

    return 0;
}