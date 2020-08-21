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
const int MAXN = 1e5+9;

ll arr[10][10];

void init(){
    for(int i = 0; i < 10; i++){
        for(int j = 1; j < 10; j++){
            if(i==0){
                arr[i][j] = 1;
                continue;
            }
            int t = i, flag = true;
            while(t){
                if((t%10)%j != 0){
                    flag = false;
                    break;
                }
                t /= 10;
            }
            arr[i][j] = arr[i-1][j];
            if(flag){
                arr[i][j]++;
            }
        }
    }
}

ll power_mod(ll num, ll pow) {
    ll ret = 1;
    while (pow) {
        if (pow & 1) {
            ret = (ret * num);
        }
        pow >>= 1LL;
        num = (num * num);
    }
    return ret;
}

ll solve(ll n, int k){
    vector<int> digits;
    ll t = n;
    while(t){
        digits.push_back(t%10);
        t /= 10;
    }

    ll ans = 0, flag = true;
    for(int i = digits.size() - 1; i >= 0; i--){
        if(digits[i]%k != 0){
            flag = false;
            ans += power_mod(arr[9][k], i) * arr[digits[i]][k];
            break;
        }
        else {
            ans += power_mod(arr[9][k], i) * (arr[digits[i]][k] - 1);
        }
    }
    if(flag){
        ans++;
    }
    return ans;
}

int main() {
    FastIO;
    init();
    int q;
    cin>>q;
    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        cout<<solve(r,k)-solve(l-1,k)<<"\n";
    }
}