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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

ordered_set del,color[MAXN];


int main() {
    FastIO;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        color[arr[i]].insert(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int x;
            cin >> x;
            arr.push_back(x);
            color[x].insert((int) arr.size() - 1);
        } else {
            int x, y;
            cin >> x >> y;
            if (color[x].size() >= y) {
                int idx = *color[x].find_by_order((int) color[x].size() - y);
                int z = del.order_of_key(idx);
                cout << arr.size() - idx - 1 - (del.size() - z) << "\n";
                del.insert(idx);
                color[x].erase(idx);
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
}