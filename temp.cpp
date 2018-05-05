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

int n;

vector<int> graph[5];
int ans;


void solve(int curr, int jumps){
    if(jumps == n && curr == 0) {
        ans++;
        return;
    }
    if(jumps >=n)
        return;
    for(auto i:graph[curr]){
        solve(i,jumps+1);
    }
}

int wolfram(int n){
    return (ll)(2*(ll)(pow(2,n)+ pow(-1.618033988,n+1) + pow(0.618033988,n+1))%MOD/5)%MOD;
}


int main() {
    FastIO;
    int t;
    cin>>t;
    for (int i = 0; i < 5; ++i) {
        graph[i].push_back((i+1)%5);
        graph[i].push_back((i-1+5)%5);
    }
    while(t--){
        n = 50 - t;
//        solve(1,1);
//        solve(4,1);
//        cout<<n<<", "<<ans<<", "<<wolfram(n-1)<<"\n";
        cout<<wolfram(n-1)<<" ";
        ans =0;
    }

    return 0;
}