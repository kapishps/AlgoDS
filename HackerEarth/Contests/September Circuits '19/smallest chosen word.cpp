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
 
const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;
 
map<int,vector<int>> m;
vector<pii> v;
 
int main() {
    FastIO;
    int n;
    cin>>n>>n>>n;
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
 
    for (int i = 0; i < s2.size(); ++i) {
        v.push_back({s2[i]-'a', i});
    }
 
    sort(v.begin(),v.end());
 
    int prev = v[0].second;
    string t;
    for (int i = 0; i < v.size(); ++i) {
        if('a' + v[i].first <= s3[0] && v[i].second >= prev){
            t += s2[v[i].second];
            prev = v[i].second;
        }
    }
    s2 = t;
 
    if(s2[0] <= s3[0]) {
        if((s3.size() <= s2.size() && s3 == s2.substr(0, s3.size())) || (s3.size() > s2.size() && s2 == s3.substr(0, s2.size()))){
            // assert(1!=1);
            cout<<s1<<s3;
        }
        else {
            string ans;
            for (int i = 0; i < s2.size(); ++i) {
                string t1 = ans + s2[i] + s3;
                string t2 = ans + s3;
                if(i > 1000){
                    cout<<s1<<s2<<s3;
                    return 0;
                }
                if(lexicographical_compare(t1.begin(), t1.end(), t2.begin(), t2.end())){
                    ans += s2[i];
                }
                else{
                    break;
                }
            }
            cout<<s1<<ans<<s3;
        }
    }
    else {
        cout<<s1<<s3;
    }
}