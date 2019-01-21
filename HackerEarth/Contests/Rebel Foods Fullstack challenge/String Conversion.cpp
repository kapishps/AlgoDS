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
const int LGNMAX = 20;


int main() {
    FastIO;
    string a, b;
    cin >> a >> b;

    vector<int> v1, v2;
    int c = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (i >= 0 && a[i - 1] != a[i]) {
            v1.push_back(c);
            c = 0;
        }
        c++;
    }
    v1.push_back(c);

    c = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (i >= 0 && b[i - 1] != b[i]) {
            v2.push_back(c);
            c = 0;
        }
        c++;
    }
    v2.push_back(c);

    if (v1.size() != v2.size())
        cout << "Not possible";
    else {
        int ans = 0;
        for (int i = 0; i < v1.size(); ++i) {
            ans += abs(v1[i] - v2[i]);
        }
        cout << ans;
    }
    return 0;
}