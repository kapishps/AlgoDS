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
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

class Matrix {
public:
    int N;
    ll M[3][3];

    Matrix() {
        N = 3;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                M[i][j] = 0;
            }
        }
    }

    Matrix(int _N, int ok) {
        N = _N;
        for (int i = 0; i < N && ok == 0; i++) {
            for (int j = 0; j < N; j++) {
                M[i][j] = 0;
            }
        }
        for (int i = 0; i < N && ok == 1; i++) {
            for (int j = 0; j < N; j++) {
                M[i][j] = 0;
            }
            M[i][i] = 1;
        }
    }

    void add(Matrix Y) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                M[i][j] = (M[i][j] + Y.M[i][j]);
                if (M[i][j] > MOD)
                    M[i][j] -= MOD;
            }
        }
    }
};

Matrix operator*(Matrix X, Matrix Y) {
    int N = X.N;
    Matrix Z(N,-1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            Z.M[i][j] = 0;
            for(int k = 0; k < N; k++) {
                Z.M[i][j] += (X.M[i][k] * Y.M[k][j]) % MOD;
                Z.M[i][j] %= MOD;
            }
        }
    }
    return Z;
}

Matrix operator^(Matrix X, ll power) {
    Matrix res(X.N,1);
    while(power) {
        if(power & 1) {
            res = res * X;
        }
        X = X * X;
        power >>= 1;
    }
    return res;
}

Matrix operator+(Matrix X, Matrix Y) {
    for (int i = 0; i < X.N; i++) {
        for (int j = 0; j < X.N; j++) {
            X.M[i][j] = (X.M[i][j] + Y.M[i][j]);
            if (X.M[i][j] > MOD)
                X.M[i][j] -= MOD;
        }
    }
    return X;
}

Matrix M(2,0);

// fib(1)^2 + fib(2)^2 + ... + fib(n)^2 = fib(n) * fib(n + 1)
// https://www.spoj.com/problems/CLASSICSEQ/

int main() {
    FastIO;
    int T;
    cin >> T;
    int t = T;
    M.M[0][0] = M.M[0][1] = M.M[1][0] = 1;
    while (t--) {
        ll n;
        cin >> n;
        Matrix ans = M ^n;
        cout <<"Case "<< T - t <<": "<< (ans.M[0][1]* ans.M[0][0]) % MOD << "\n";
    }
    return 0;
}