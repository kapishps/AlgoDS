#include<bits/stdc++.h>
using namespace std;

int solve (vector<int> A, long long K) {
    map<long long, long long> m;

    for (int i = 0; i < A.size(); i++) {
        int x = A.size();
        long long cnt = 1;
        while (x > i) {
            m[A[i]] += cnt * A.size();
            cnt++;
            x /= 2;
        }
    }

    for (auto i : m) {
        if (i.second < K)
            K -= i.second;
        else
            return i.first;
    }
    return -1;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i_A = 0; i_A < N; i_A++) {
            cin >> A[i_A];
        }
        long long K;
        cin >> K;

        int out_;
        out_ = solve(A, K);
        cout << out_;
        cout << "\n";
    }
}