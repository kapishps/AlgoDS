#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = INFINITY;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

ll solve(int n,ll a[]){
    //Also handles all negative numbers
    ll sum=a[0],max_till_here=a[0];
    for (int i = 1; i < n; ++i) {
        max_till_here=max(a[i],max_till_here+a[i]);
        sum = max(sum, max_till_here);
    }
    return sum;
}

int main() {
//    Boost;
    int n;
    cin>>n;
    ll arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    cout<<solve(n,arr);
    return 0;
}