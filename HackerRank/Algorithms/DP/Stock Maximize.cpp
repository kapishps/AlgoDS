#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair

const int MOD=1e9+7;
const int MAXN=1e6+5;

ll solve(int a[],int n){
    ll ans=0,sell_amount=a[n-1];
    for (int i=n-2;i>=0;i--){
        if(sell_amount > a[i])
            ans+= sell_amount-a[i];
        else
            sell_amount=a[i];
    }
    return ans;
}

//https://www.hackerrank.com/challenges/stockmax

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        cout<<solve(a,n)<<endl;
    }
    return 0;
}
