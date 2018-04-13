#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <unordered_set>
#include <iomanip>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

int prime[MAXN],a[MAXN],ans[MAXN];

int fun(int n, int i) {
    if(n==1)
        return 0;
    if(n%i==0)
        return 1+ fun(n/i,i);
    return 0;
}

void SieveOfEratosthenes(int n) {
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]==0) {
            for (int j = i * 2; j <= n; j += i)
                prime[j]+=fun(j,i);
            prime[i] = 1;
        }
        cout<<i<<" "<<prime[i]<<"\n";
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    SieveOfEratosthenes(1000009);
    for(int i=0; i< n ; i++){
        cin>>a[i];
        ans[i] = prime[a[i]];
    }
    sort(ans,ans+n);
    for(int i=1; i< n ; i++){
        ans[i] += ans[i-1];
    }
    while(q--){
        int k;
        cin>>k;
        cout<<upper_bound(ans,ans+n,k)-ans<<"\n";
    }
    return 0;
}
