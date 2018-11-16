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

map<int,int> a,b;

int main() {
    FastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b[x] = 1;
    }

    int ans = 0;
    for (auto i:a) {
        for (auto j:b) {
            if (__gcd(i.first, j.first) == 1)
                ans = max(ans, i.first + j.first);
        }
    }

    cout<<ans;
}