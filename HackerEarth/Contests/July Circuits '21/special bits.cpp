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

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

int arr[MAXN];

ll solve(ll l, ll r, ll k){
    bitset<64> bset(l);
    if(l > r || r < ((1LL<<k)-1)){
        return -1;
    }
    if(__builtin_popcountll(l) == k){
        return l;
    }
    
    if(__builtin_popcountll(l) > k){
        for(int i = 0; i < 63; i++){
            bset.reset(i);
            bset.set(i+1, 1);
            if(bset.count() < __builtin_popcountll(l) && bset.to_ullong() > l){
                break;
            }
        }
        return solve(bset.to_ullong(), r, k);
    }
    else {
        for(int i = 0; i < 63; i++){
            bset.set(i, 1);
            if(bset.to_ullong() <= r && bset.count() == k){
                return bset.to_ullong();
            }
        }
    }
    return -1;
}

ll bruteforce(ll l, ll r, ll k){
    if(l > r || r < ((1LL<<k)-1)){
        return -1;
    }
    if(__builtin_popcountll(l) == k){
        return l;
    }
    for(ll i = l; i <= r; i++){
        if(__builtin_popcountll(i) == k)
            return i;
    }
    return -1;
}

void test() {
    ll t, l, r, k;
    srand(time(0));
    for(int i = 0; i < 10; i ++){
        l = rand();
        r = rand();
        k = rand()%64;
        if(solve(l,r,k) != bruteforce(l,r,k)){
            cout<<l<<" "<<r<<" "<<k<<"\n";
        }
    }
}
 
int main() {
    FastIO;
    // test();
    ll t, l, r, k;
    cin>>t;
    while(t--){
        cin>>l>>r>>k;
        cout<<solve(l,r,k)<<"\n";
    }
}