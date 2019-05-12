// There are N students in a class and each student has a number denoted by an array A.
// The teacher will select three students and give a task to each of them. The first
// student has to find a number of subsets of students having cumulative xor less than K.
// The second student has to find a number of subsets of students having cumulative xor
// equal to K. The third student has to find a number of subsets of students having
// cumulative xor greater than K. Let the three numbers returned by the selected students
// are a, b and b. You need to find the value of :
// ((a+b)*(a+b)) + ((a+c)*(a+c)) + ((c+b)*(c+b)) - ((a*a) + (b*b) + (c*c))

//Similar
// https://apps.topcoder.com/wiki/display/tc/SRM+590
// https://www.hackerearth.com/practice/notes/gaussian-elimination/
// https://codeforces.com/blog/entry/10229

// Possible Topics
// gaussian elimination



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
const int MAXN = 1e5+9;

int arr[MAXN], b[20], number2[MAXN];
int A[20][MAXN];
ll pow2[MAXN];

ll runk(int M, int N, int a[20][100009], int b[], int p) {
    // M equations, N variables, modulo p
    ll ans = 0;


    //bool* used= new bool[M];
    vector<bool> used(M, false);

    // Using Gauss-Jordan in [ A : b ] to make it in row-echellon form.
    // So that we can find the rank. We also need to make sure that the
    // rank of [ A ] is equal to the rank of [A : b], else there are
    // no solutions
    for (int j = 0; j < N; j++) {
        int i = 0;
        while ((i < M) && (used[i] || (a[i][j] == 0))) {

            i++;
        }
        if (i == M) continue;
        ans++;
        used[i] = true;
        // cout<<i<<endl;
        for (int k = 0; k < M; k++)
            if (!used[k]) {
                // Find a value of coef equal to (-a[k][j] / a[i][j]);
                // we can just try 0,1,..,p-1 until we find one.
                int coef = 0;
                while ((a[i][j] * coef + a[k][j]) % p != 0) {
                    coef++;
                }
                for (int l = 0; l < N; l++) {
                    a[k][l] = (a[k][l] + a[i][l] * coef) % p;
                }
                b[k] = (b[k] + b[i] * coef) % p;
            }
    }

    // If rank of [A] is not equal to the rank of [A : b]
    for (int i = 0; i < M; i++) {
        if (!used[i] && b[i] != 0) {

            return -1;
        }
    }

    return ans;
}

ll numberOfExactWays(int n, int number[], long must) {
    ll res = 0;
    // make the system of equations
    int M = 20; //one equation per bit
    int N = n; // one variable per card

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if ((number[j] & (pow2[i])) != 0) {
                A[i][j] = 1;
            } else {
                A[i][j] = 0;
            }
        }
        if ((must & (1L << i)) != 0) {
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }
    // Find the rank of the system of equations:
    ll r = runk(M, N, A, b, 2);
    // Number of free variables is equal to N minus rank.
    return (r == -1) ? 0 : (pow2[N - r]);
}

ll numberOfLesserWays(int n, int number[], int limit) {
    ll res = 0;
    for (int i = 0; i < 20; i++) {
        if ((limit & (1L << i)) != 0) {
            //Truncate the last i bits, set bit #i to 0.
            long l2 = limit >> (i + 1) << 1;
            //Truncate the last i bits of each of the cards:
            for (int j = 0; j < n; j++) {
                number2[j] = number[j] >> i;
            }
            //Solve the exact case, add the result.
            res += numberOfExactWays(n, number2, l2);
            res %= MOD;
        }

    }
    return res;
}

void precalc(){
    pow2[0] = 1;
    for (int i = 1; i < 100002; ++i) {
        pow2[i] = 2*pow2[i-1];
        pow2[i] %= MOD;
    }
}

int main() {
    FastIO;
    precalc();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        ll a = numberOfExactWays(n, arr, k);
        ll b = numberOfLesserWays(n, arr, k);
        ll c = (pow2[n] + MOD - a + MOD - b) % MOD;

        cerr<<a<<" "<<b<<" "<<c;

        ll ans = (a + b) * (a + b);
        ans %= MOD;
        ans += (a + c) * (a + c);
        ans %= MOD;
        ans += (c + b) * (c + b);
        ans %= MOD;
        ans = ans + MOD - (a*a) - (b*b) - (c*c);
        ans %= MOD;
        cout <<ans<<"\n";
    }
    return 0;
}