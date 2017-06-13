#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

bitset<10000010> prime;

void SieveOfEratosthenes(ll n) {
    prime.set();
    prime[0] = prime[1] = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * 2; j <= n; j += i)
                prime[j] = 0;
        }
    }
}

//Modular Multiplication
ll mul_mod(ll a, ll b, ll M = MOD) {        //(a * b) % M
    if (a < b)
        swap(a, b);
    ll res = 0, x = a;
    while (b > 0) {
        if (b & 1) {
            res = (res + x)%M;
        }
        x = (x * 2)%M;
        b >>= 1LL;
    }
    return res % M;
}

//Modular Exponentiation
ll power_mod(ll a, ll p, ll M = MOD) {      //n^p % M
    ll x = a, res = 1;
    while (p) {
        if (p & 1)
            res = mul_mod(res, x, M);
        x = mul_mod(x, x, M);
        p >>= 1LL;
    }
    return res;
}

ll GCD(ll a, ll b) {
    if(b==0)
        return a;
    return GCD(b, a % b);
}

ll LCM(ll a, ll b) {
    return (a*b)/GCD(a, b);
}

ll d, x, y;
void extendedEuclid(ll a, ll b) {       //Ax + By = GCD(A, B) = d
    if(b == 0) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(b, a%b);
        ll temp = x;
        x = y;
        y = temp - (a/b)*y;
    }
}

//Modular Multiplicative Inverse
ll modulo_Inv(ll a, ll M) {         //using Extended Euclidean Algorithm
    extendedEuclid(a, M);
    return (x % M + M) % M;     //x may be negative
}

//Modular Multiplicative Inverse (Applicable only when M is prime)
ll modulo_inv(ll n, ll M = MOD){      //using Fermat's Little Theorem.
    return power_mod(n, M - 2, M);
}

/*
Modular Arithmetic
    1. (a+b)%c = (a%c + b%c )%c
    2. (a * b)%c = ((a%c) * (b%c))%c
    3. (a - b)%c = ((a%c) - (b%c) +c) %c
    4. (a / b)%c = ((a%c) * (inv(b) %c))%c
inv(b) is the multiplicative modulo inverse of b with c
*/

int main() {
//    Boost;
    ll n;
    cin >> n;
    SieveOfEratosthenes(n);
    for (int i = 0; i < n; ++i) {
        if (prime[i])
            cout << i << " ";
    }
    return 0;
}
