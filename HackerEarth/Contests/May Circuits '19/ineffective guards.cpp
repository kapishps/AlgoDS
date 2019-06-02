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
const int MAXN = 2e5+9;

vector<int> pve,nve;
int imp[MAXN];
map<int, int> map1;
vector<pii> a,b;

vector<int> j[MAXN];

int main() {
    FastIO;
    int n,m;
    cin>>n>>m;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin>>x>>y;
        b.push_back({x,y});
    }

    sort(all(a));
    sort(all(b));

    for (int i = 0; i < m; ++i) {
        int x= b[i].first,y=b[i].second;
        int idx = -1;
        pii t = {x,y};
        int uidx = lower_bound(a.begin(), a.end(), t) - a.begin();
        for (int j = uidx; j >= 0; j--) {
            if(abs(y-a[j].second) <= x - a[j].first){
                if(idx == -1){
                    idx = j;
                }
                else{
                    idx = -2;
                    break;
                }
            }
        }

        if(idx != -1 && idx != -2){
            imp[idx] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += imp[i];
    }
    cout<<n - ans;

}