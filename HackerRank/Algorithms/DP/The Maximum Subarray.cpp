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

ll kadane(ll a[],int n){
    ll sum=a[0],max_till_here=a[0];
    for (int i = 1; i < n; ++i) {
        max_till_here=max(a[i],max_till_here+a[i]);
        sum = max(sum, max_till_here);
    }
    return sum;
}

//https://www.hackerrank.com/challenges/maxsubarray

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        ll a[n],nc=0;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            if(a[i]>0)
                nc+=a[i];
        }
        ll c=kadane(a,n);
        if(c<0)
            cout<<c<<" "<<c<<endl;
        else
            cout<<c<<" "<<nc<<endl;
    }
    return 0;
}
