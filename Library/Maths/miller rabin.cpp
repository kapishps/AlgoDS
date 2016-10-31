#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

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

ll mul_mod(ll a, ll b, ll M = MOD) {        //(a * b) % M
    if (a < b)
        swap(a, b);
    ll res = 0, x = a;
    while (b > 0) {
        if (b & 1) {
            res = (res + x) % M;
        }
        x = (x * 2) % M;
        b >>= 1LL;
    }
    return res % M;
}

ll power_mod(ll n, ll p, ll M = MOD) {      //n^p % M
    ll x = n, res = 1;
    while (p) {
        if (p & 1)
            res = mul_mod(res, x, M);
        x = mul_mod(x, x, M);
        p >>= 1LL;
    }
    return res;
}

bool Miller_Rabin(ll p,int iteration) {     //20 iterations enough for most cases
    if (p < 2)
        return false;
    if (p != 2 && p % 2 == 0)
        return false;
    ll s = p - 1;
    while (s % 2 == 0) {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++) {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = power_mod(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1) {
            mod = mul_mod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
//    Boost;
    srand(time(0));
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if (Miller_Rabin(n,20))
            cout<<"prime"<<"\n";
        else
            cout<<"composite"<<"\n";
    }
    return 0;
}