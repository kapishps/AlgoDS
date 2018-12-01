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

set<int> chars[26];
map<pii,int> M;


int main() {
    FastIO;
    int n, q;
    cin >> n >> q;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for(auto j:s[i])
            chars[j-'a'].insert(i);
    }

    while (q--) {
        int u, v;
        cin>>u>>v;
        u--;
        v--;
    }
}