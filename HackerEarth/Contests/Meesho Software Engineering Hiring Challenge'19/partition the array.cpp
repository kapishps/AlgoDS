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

ll arr[MAXN];
ld logarr[MAXN];

int main() {
    FastIO;
    int n;
    cin>>n;
    ld sum = 0, diff = inf, pre = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        logarr[i] = log10l(arr[i]);
        sum += logarr[i];
    }
    int ans = 1;
    for(int i = 0;i< n;i++){
        pre += logarr[i];
        sum -= logarr[i];
        if(diff - abs(pre - sum) > 0.00001){
            diff = abs(pre - sum);
            ans = i+1;
        }
    }
    cout<<ans;
}