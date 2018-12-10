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
    int n, q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, pair<int, pii>>> que;


    while (q--) {
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        if (t == 1 && x >= 0) {
            t = 3;
            que.push_back(mp(t, mp(x, mp(l, r))));
        }
        else
            que.push_back(mp(t, mp(x, mp(l, r))));
    }

    sort(que.begin(), que.end());

    for (int i = 0; i < que.size(); ++i) {
        int t, l, r, x;
        t = que[i].first;
        x = que[i].second.first;
        l = que[i].second.second.first;
        r = que[i].second.second.second;

        if (t == 3)
            t = 1;

        if (t == 1) {
            l--;
            r--;
            for (int j = l; j <= r; ++j) {
                a[j] += x;
            }
        } else {
            l--;
            r--;
            for (int j = l; j <= r; ++j) {
                a[j] = x;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}