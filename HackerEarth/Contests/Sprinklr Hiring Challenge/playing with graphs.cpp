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
const int MAXN = 3e5+9;

int child[MAXN],arr[MAXN];
vector<pii> qry;
vector<ll> ans;
set<int> s;

int findchild(int x) {
    if (x == -1)
        return -1;
    if (x != child[x])
        child[x] = findchild(child[x]);
    return child[x];
}

void unionset(int x, int y) {
    int cx = findchild(x), cy = findchild(y);
    if (cx != cy) {
        child[cx] = cy;
    }
    else{
        child[cx] = -1;
    }
}

void initialiseset(int start, int end) {
    for (int i = start; i <= end; ++i) {
        child[i] = i;
    }
}

int main() {
    FastIO;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        s.insert(i);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        qry.push_back({a, b});

        if (a == 2)
            s.erase(b);
    }

    initialiseset(0, n);
    for (auto i : s) {
        if(arr[i] != 0)
            unionset(i, arr[i]);
    }

    reverse(qry.begin(), qry.end());
    for (int i = 0; i < q; ++i) {
        if (qry[i].first == 1) {
            ans.push_back(findchild(qry[i].second));
        }
        else {
            unionset(qry[i].second, arr[qry[i].second]);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == -1)
            cout << "LOOP" << "\n";
        else
            cout << ans[i] << "\n";
    }

    return 0;
}
