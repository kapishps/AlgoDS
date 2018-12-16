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
const int MAXN = 1e6+9;

bitset<10000010> prime;
vector<int> primesq;
int a[MAXN];

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

void markPrimeSq(){
    for (int i = 2; i <= 1010; ++i) {
        if(prime[i])
            primesq.push_back(i*i);
    }
}

int main() {
    FastIO;
    int n,k;
    cin>>n>>k;

    SieveOfEratosthenes(MAXN);
    markPrimeSq();

    vector<int> diff;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int idx = lower_bound(primesq.begin(), primesq.end(), a[i]) - primesq.begin();
        if(idx == 0){
            diff.push_back(primesq[idx] - a[i]);
        }
        else
            diff.push_back(min(primesq[idx] - a[i], a[i] - primesq[idx - 1]));
    }

    sort(diff.begin(),diff.end());
    int ans = n - k;
    for (int i = 0; i < k; ++i) {
        cerr<<diff[i]<<" ";
        ans += diff[i];
    }

    cout<<ans;
    return 0;
}