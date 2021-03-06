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


ll a[MAXN], ans[MAXN], answer = 0, BLOCK;
unordered_map<int,int> cnt;

struct node {
    int L, R, i;
} q[MAXN];

bool cmp(node x, node y) {
    if (x.L / BLOCK != y.L / BLOCK)
        return x.L / BLOCK < y.L / BLOCK;
    return x.R < y.R;
}

void add(int index) {
    cnt[a[index]]++;
    if (cnt[a[index]] % 2 == 1)
        answer += a[index] * cnt[a[index]];
    if (cnt[a[index]] % 2 == 0)
        answer -= a[index] * (cnt[a[index]] - 1);
}

void remove(int index) {
    cnt[a[index]]--;
    if (cnt[a[index]] % 2 == 1)
        answer += a[index] * cnt[a[index]];
    if (cnt[a[index]] % 2 == 0)
        answer -= a[index] * (cnt[a[index]] + 1);
}


// Score 20/100 Rest Timeout

int main() {
    FastIO;
    int n, m;
    cin >> n;
    BLOCK = (int) sqrt(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> q[i].L >> q[i].R;
        q[i].L--;
        q[i].R--;
        q[i].i = i;
    }

    sort(q, q + m, cmp);
    int currentL = 0, currentR = 0;
    for (int i = 0; i < m; i++) {
        int L = q[i].L, R = q[i].R;
        while (currentR <= R) {
            add(currentR);
            currentR++;
        }
        while (currentR > R + 1) {
            remove(currentR - 1);
            currentR--;
        }
        while (currentL < L) {
            remove(currentL);
            currentL++;
        }
        while (currentL > L) {
            add(currentL - 1);
            currentL--;
        }
        ans[q[i].i] = answer;
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}
