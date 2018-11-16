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

string arr[MAXN];
map<string, int> M;


int main() {
    FastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        M[arr[i]]++;
    }
    int ans =0;
    for(auto i: M){
        string s = i.first;
        reverse(s.begin(),s.end());
        if(s.size() > 1 && M[s] >= i.second){
            ans += M[i.first];
            M[i.first] = 0;
        }
    }
    cout<<ans;
}