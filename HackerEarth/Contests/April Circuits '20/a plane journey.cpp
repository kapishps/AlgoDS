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

int a[MAXN];
vector<int> allotment[MAXN];

int main() {
    FastIO;
    int n,m;
    cin>>n>>m;
    vector<int> p(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    sort(a, a+n);
    sort(p.begin(), p.end());
    if(p[m-1] < a[n-1]){
        cout<<-1;
        return 0;
    }
    int max_trips = 0, total =0;
    for(int i = 0; i <n;i++){
        int idx = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
        allotment[idx].push_back(i);
    }
    for(int i = m-1; i >= 0;i--){
        total += allotment[i].size();
        max_trips = max(max_trips, (int)ceil((float)total/(float)(m - i)));
    }
    cout<<(2*(max_trips-1))+1;
}