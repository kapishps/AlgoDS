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

int arr[MAXN];

int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        assert(s.size() == n);
        arr[0] = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'A')
                arr[i+1] = 0;
            else
                arr[i+1] = 1;

            arr[i+1] += arr[i];
            // cout<<arr[i]<<" ";
        }

        int ans = inf;
        for(int i=0;i<=n;i++){
            ans = min(ans, n - arr[n] + arr[i] + arr[i] - i);
        }
        cout<<ans<<"\n";
    }

}