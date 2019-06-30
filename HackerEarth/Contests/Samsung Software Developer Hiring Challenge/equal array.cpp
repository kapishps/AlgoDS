#include<bits/stdc++.h>
using namespace std;

int getMinimumSwapsRequiredToMakeArrayEqual (vector<char> a, vector<char> b) {
    map<int, int> m;
    for (auto i : a) {
        m[i]++;
    }
    for (auto i : b) {
        m[i]++;
    }
    for (auto i : m) {
        if (i.second % 2 == 1)
            return -1;
    }
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i])
            cnt++;
    }

    return (a.size() - cnt) / 2;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<char> a(n);
    for (int i_a = 0; i_a < n; i_a++) {
        cin >> a[i_a];
    }
    vector<char> b(n);
    for (int i_b = 0; i_b < n; i_b++) {
        cin >> b[i_b];
    }

    int out_;
    out_ = getMinimumSwapsRequiredToMakeArrayEqual(a, b);
    cout << out_;
}