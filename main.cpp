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
const int MAXN = 2e5+9;

void finalPrice(vector<int> prices) {
    vector<int> sml(prices.size());
    vector<int> ind;
    stack<int> st;
    long long cost = 0;
    for (int i = prices.size()-1; i >= 0; i--) {
        while(!st.empty() && st.top() > prices[i])
            st.pop();
        if(st.empty()){
            ind.push_back(i);
            sml[i] = prices[i];
        }
        else{
            sml[i] = prices[i] - st.top();
        }
        st.push(prices[i]);
        cost += sml[i];
    }

    sort(ind.begin(),ind.end());
    cout<<cost<<"\n";
    for (int i = 0; i < ind.size(); ++i) {
        cout<<ind[i]<<" ";
    }
}

int main() {
    FastIO;
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin>>v[i];
    }
    finalPrice(v);
    return 0;
}