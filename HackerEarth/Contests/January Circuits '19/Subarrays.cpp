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
const int MAXN = 3e5+9;

ll arr[MAXN];
map<ll,ll> M;

int main() {
    FastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll max_ending_here = 0, max_so_far = 0;

    for (int i = 0; i < n; ++i) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        if(max_so_far <= max_ending_here){
            max_so_far = max_ending_here;
            M[max_ending_here]++;
        }
    }

    cout<<max_so_far<<" "<< M[max_so_far];

    return 0;
}