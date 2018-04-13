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
const int MAXN = 1e6+9;

int factors[MAXN];

int util(int n, int i) {
    if (n == 1)
        return 0;
    if (n % i == 0)
        return 1 + util(n / i, i);
    return 0;
}

void precalc() {
    for (int i = 2; i < MAXN; i++) {
        if (factors[i] == 0) {
            for (int j = i * 2; j <= MAXN; j += i) {
                factors[j] += util(j, i);

            }
        }
    }
    for (int i = 2; i < MAXN; ++i) {
        if (factors[i] == 0)
            factors[i] = 1;
    }
}

int main(){
    FastIO;
    precalc();
//    cout<<"\n"<<util(3062,2) <<" ";

    int n,q;
    cin>>n>>q;

    int a[n];
    vector<ll> sum;

    for(int i=0; i< n ; i++){
        cin>>a[i];
        sum.push_back((ll)factors[a[i]]);
    }

    sort(sum.begin(),sum.end());
    for(int i=1; i< n ; i++){
        sum[i] += sum[i-1];
    }

    while(q--){
        ll k;
        cin>>k;
        cout<<upper_bound(sum.begin(),sum.end(),k)-sum.begin()<<"\n";
    }

    return 0;
}