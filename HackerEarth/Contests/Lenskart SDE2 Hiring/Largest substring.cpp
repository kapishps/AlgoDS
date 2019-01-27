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

map<int,int> M;

int main() {
    FastIO;
    int n;
    cin>>n;
    string s;
    cin>>s;

    ll ans = 0,sum = 0, temp;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            sum++;
        else
            sum--;

        if (sum > 0) {
            ans = i + 1;
        }
        else if (sum <= 0) {
            if (M.find(sum - 1) != M.end()) {
                temp = i - M[sum - 1];
                ans = max(ans, temp);
            }
        }

        if (M.find(sum) == M.end())
            M[sum] = i;
    }

    cout<<ans;

    return 0;
}