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
    int t;
    cin >> t;
    while (t--) {
        ll a[16];
        for (int i = 0; i < 16; ++i) {
            cin >> a[i];
        }
        ll flash = 0, cisco = 0;
        for (int i = 8; i < 12; ++i) {
            flash += max(a[i - 8] / 2, a[i - 8] - (a[i - 4] * a[i]));
        }
        for (int i = 12; i < 16; ++i) {
            cisco += max(a[i - 12] / 2, a[i - 12] - (a[i - 8] * a[i]));
        }
        if (flash > cisco)
            cout << "Flash\n";
        if (cisco > flash)
            cout << "Cisco\n";
        if (flash == cisco) {
            ll t1 = 0, t2 = 0;
            for (int i = 8; i < 12; ++i) {
                t1 = max(t1, a[i]);
            }
            for (int i = 12; i < 16; ++i) {
                t2 = max(t2, a[i]);
            }
            if (t2 > t1)
                cout << "Flash\n";
            if (t1 > t2)
                cout << "Cisco\n";
            if (t1 == t2)
                cout << "Tie\n";
        }
    }
}