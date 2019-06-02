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
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 3e5+9;

int in[MAXN], out[MAXN], parent[MAXN];
pii map1[MAXN];
vector<pair<pii,int>> v;

int main() {
    FastIO;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>in[i];
    }

    for (int i = 0; i < n; ++i) {
        cin>>out[i];
        map1[i] = {in[i],out[i]};
        v.push_back({{in[i], out[i]}, i});
    }

    sort(all(v));
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            st.push(v[i].second);
            parent[v[i].second] = 0;
        }
        else {
            if (v[i].first.first < map1[st.top()].second) {
                if (v[i].first.second - v[i].first.first > 1) {
                    parent[v[i].second] = st.top() + 1;
                    st.push(v[i].second);
                }
                else {
                    parent[v[i].second] = st.top() + 1;
                }
            }
            else {
                while (v[i].first.first >= map1[st.top()].second) {
                    st.pop();
                }
                if (v[i].first.second - v[i].first.first > 1) {
                    parent[v[i].second] = st.top() + 1;
                    st.push(v[i].second);
                }
                else {
                    parent[v[i].second] = st.top() + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout<<parent[i]<<" ";
    }

}