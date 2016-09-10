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

int binary_search(ll a[],int start,int end,ll x){
    if(end>=start){
        int mid = start + (end-start)/2;
        if (a[mid]==x)
            return mid;
        if(a[mid] > x)
            return binary_search(a,start,mid-1,x);
        return binary_search(a,mid+1,end,x);
    }
    return -1;
}

int solve(ll a[],int start,int end){
    ll x=a[end]-a[start-1];
    ll y=a[start-1];
    if(start < 1 || start>end || x%2==1)
        return 0;
    int m=binary_search(a,start,end,y+(x/2));
    if(m==-1)
        return 0;
    else
        return max(solve(a,start,m),solve(a,m+1,end))+1;
}

//https://www.hackerrank.com/challenges/array-splitting

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        ll a[n+1];
        a[0]=0;
        for (int i = 1; i <=n; ++i) {
            int c;
            cin>>c;
            a[i]=a[i-1]+c;
//            cout<<a[i]<<" ";
        }
        if(a[n]==0)
            cout<<n-1<<endl;
        else
            cout<<solve(a,1,n)<<endl;
    }
    return 0;
}
