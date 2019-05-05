#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

stack<pii> st;

int main() {
    FastIO;
    ll n,k;
    cin>>n>>k;
    if(k > 1e8){
        cout<<1<<"/"<<2<<"\n";
        return 0;
    }
    for (int i = 2; i <= n; ++i) {
        st.push({1,i});
    }
    st.push({0,1});
    pii curr, temp;
    while(k--){
        curr = st.top();
        st.pop();
        while(!st.empty()){
            temp = st.top();
            if(curr.second + temp.second <= n){
                st.push({curr.first+temp.first, curr.second+temp.second});
            }
            else
                break;
        }
    }
    cout<<curr.first<<"/"<<curr.second;

    return 0;
}