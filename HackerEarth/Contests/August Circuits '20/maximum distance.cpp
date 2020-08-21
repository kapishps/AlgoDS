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
const int MAXN = 4e5+9;

ll arr[MAXN];
set<int> m;

int main() {
    FastIO;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>arr[i];
        if(arr[i] == 1){
            m.insert(i);
        }
    }
    
    int q;
    cin>>q;
    while(q--){
        ll t,s,e,x;
        cin>>t;
        if(t == 3){
            cin>>s;
            assert(s == 1);
            if(m.size() == 0)
                cout<<-1<<"\n";
            else{
                int ans = *m.rbegin() - *m.begin() + 1;
                cout<<ans<<"\n";
            }
        }
        else{
            cin>>s>>e>>x;
            s--;
            e--;
            if((t == 1 && x >= 1) || (t == 2 && x > 1)){
                set<int> temp = m;
                for(auto i: temp){
                    if(i >= s && i <= e){
                        m.erase(i);
                    }
                }
            }
        }
    }
}