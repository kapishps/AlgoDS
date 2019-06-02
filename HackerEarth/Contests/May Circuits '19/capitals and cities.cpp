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
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 3e5+9;

ll pre[MAXN], post[MAXN];
pair<ll,ll> arr[MAXN];

int main() {
    FastIO;
    ll n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << 1 << " " << 0;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr, arr + n);

    pair<ll, ll> ans = {1e18, inf};
    for (ll i = 1; i < n; ++i) {
        pre[i] = pre[i - 1];
        pre[i] += i * abs(arr[i].first - arr[i - 1].first);
    }

    for (ll i = n - 1; i >= 0; i--) {
        post[i] = post[i + 1];
        post[i] += (n - i - 1) * abs(arr[i].first - arr[i + 1].first);
        ll sum = pre[i] + post[i];
        if (sum <= k) {
            if (ans.first > (k - sum) % 2) {
                ans.first = (k - sum) % 2;
                ans.second = arr[i].second;
            }
            else if (ans.first == (k - sum) % 2) {
                ans.second = min(arr[i].second, ans.second);
            }
        }
        else {
            if (ans.first > sum - k) {
                ans.first = sum - k;
                ans.second = arr[i].second;
            }
            else if (ans.first == sum - k) {
                ans.second = min(arr[i].second, ans.second);
            }
        }
    }

    cout << ans.second << " " << ans.first;

}