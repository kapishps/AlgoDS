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

int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        int flag = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1]){
                flag = 0;
                break;
            }
        }
        if(flag || s.size() == 1){
            cout<<-1<<"\n";
        }
        else{
            cout<<s<<"\n";
        }
    }
}