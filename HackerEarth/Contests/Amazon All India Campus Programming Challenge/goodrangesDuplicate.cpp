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
const int MAXN = 1e6+9;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

ordered_set tree1;

int a[MAXN];
map<int, pii> map1;
map<int,int> cnt;

int main() {
    FastIO;
    int n, q;
    cin >> n >> q;
    int minX, maxX;
    ll sum = 0;
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
        if (i == 0) {
            minX = a[i];
            maxX = a[i];
            map1[a[i]] = {1, n};
            sum += (1 + n);
            cout << sum << "\n";
        }
        else {
            if (a[i] < minX) {
                pii t1 = map1[minX];
                map1[a[i]] = {t1.first, minX - 1};
                map1[minX] = {a[i] + 1, t1.second};
                sum += (a[i] + minX);
                cout << sum << "\n";
                minX = a[i];
            }
            else if (a[i] > maxX) {
                pii t1 = map1[maxX];
                map1[a[i]] = {maxX + 1, t1.second};
                map1[maxX] = {t1.first, a[i] - 1};
                sum += (a[i] + maxX);
                cout << sum << "\n";
                maxX = a[i];
            }
            else {
                int idx = tree1.order_of_key(a[i]);
                int hi = *tree1.find_by_order(idx);

                if (hi == a[i] && cnt[hi] == 1) {
                    pii t = map1[hi];
                    map1[hi] = {hi, hi};
                    sum -= (t.first + t.second);
                    cout << sum << "\n";
                }
                else if (hi != a[i]) {
                    int lo = *tree1.find_by_order(idx - 1);

                    if (cnt[lo] > 1 || cnt[hi] > 1) {
                        if (cnt[lo] > 1 && cnt[hi] > 1) {
                            map1[a[i]] = {lo + 1, hi - 1};
                            sum += (lo + hi);
                            cout << sum << "\n";
                        }
                        else if (cnt[lo] > 1) {
                            pii t2 = map1[hi];
                            map1[a[i]] = {t2.first, hi - 1};
                            map1[hi] = {a[i] + 1, t2.second};
                            sum += (a[i] + hi);
                            cout << sum << "\n";
                        }
                        else {
                            pii t1 = map1[lo];
                            map1[lo] = {t1.first, a[i] - 1};
                            map1[a[i]] = {lo + 1, t1.second};
                            sum += (a[i] + lo);
                            cout << sum << "\n";
                        }
                    }
                    else {
                        pii t1 = map1[lo];
                        pii t2 = map1[hi];
                        map1[lo] = {t1.first, a[i] - 1};
                        map1[a[i]] = {t2.first, t1.second};
                        map1[hi] = {a[i] + 1, t2.second};
                        sum += (2 * a[i]);
                        cout << sum << "\n";
                    }
                }
            }
        }
        cnt[a[i]]++;
        tree1.insert(a[i]);
        for (auto j : map1) {
            cout << "(" << j.second.first << "," << j.second.second << "), ";
        }
        cout << "\n";
    }
    return 0;
}