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
const int MAXN = 5e3+9;


int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<int, string> s[n];
        map<string, int> M;
        for (int i = 0; i < n; ++i) {
            int x;
            string temp;
            cin >> x >> temp;
            s[i] = make_pair(x, temp);
            M[temp] += x;
        }

        if (M["A"] == 0 || M["B"] == 0) {
            cout << max(M["A"], M["B"]) << "\n";
            continue;
        }

        ll lcm = (1LL * M["A"] * M["B"]) / __gcd(M["A"], M["B"]);
        pair<ll, ll> ratio = make_pair(lcm / M["B"], lcm / M["A"]);

        ll ans = 0, sum = 0, suma = 0, sumb = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i].second == "A") {
                if (sum < 0 && abs(sum) % ratio.second == 0 && abs(sum) / ratio.second <= s[i].first)
                    ans++;
                sum += ratio.second * s[i].first;
            }
            else {
                if (sum > 0 && abs(sum) % ratio.first == 0 && abs(sum) / ratio.first <= s[i].first)
                    ans++;
                sum -= ratio.first * s[i].first;
            }
        }
        cout << ans << "\n";
    }

}