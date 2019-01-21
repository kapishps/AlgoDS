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


int main() {
    FastIO;
    int n;
    cin >> n;
    int day[31] = {0}, arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        day[arr[i]]++;
    }

    int dp[31] = {0};
    for (int i = 1; i < 31; ++i) {
        if (day[i] == 1)
            dp[i] = dp[i - 1] + 199;
        else
            dp[i] = dp[i - 1];

        if (i >= 7)
            dp[i] = min(dp[i], dp[i - 7] + 699);
        if (i >= 30)
            dp[i] = min(dp[i], dp[i - 30] + 2499);
    }

    cout << dp[30];
    return 0;
}