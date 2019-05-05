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

int arr[MAXN];
vector<pii> a;
vector<int> b,c;

int main() {
    FastIO;
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < 2*n; ++i) {
        cin>>arr[i];
        a.push_back({arr[i],i+1});
    }

    if(k > 2){
        sort(all(a));
        for (int i = 0; i < n; ++i) {
            b.push_back(a[i].second);
        }
        for (int i = 0; i < n; ++i) {
            c.push_back(a[i+n].second);
        }
        sort(all(b));
        sort(all(c));
        for (int i = 0; i < n; ++i) {
            if(i%3 == 2){
                int t = b[i];
                b[i] = c[i];
                c[i] = t;
            }
        }
    }
    else{
        for (int i = 0; i < 2*n; ++i) {
            if(i%2 == 0)
                b.push_back(i+1);
            else
                c.push_back(i+1);
        }

        int score1 = 0, score2 = 0;
        for (int i = 0; i < n; ++i) {
            if(a[b[i]-1] < a[c[i]-1])
                score1++;
            else
                score2++;
        }
        if(score2 > score1)
            swap(b,c);
    }

    sort(all(b));
    sort(all(c));
    assert(b.size() == c.size());

    for (int i = 0; i < n; ++i) {
        cout<<b[i]<<" ";
    }
    cout<<"\n";
    for (int i = 0; i < n; ++i) {
        cout<<c[i]<<" ";
    }
    return 0;
}