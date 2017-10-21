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

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

vector<int> tree[MAXN];
int c[MAXN];


/*
 * if leaf node then +(n-1)*2*c[i]
 *
 * */

int main() {
    FastIO;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        cin>>c[i];
    }
    return 0;
}