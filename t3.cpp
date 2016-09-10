#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair

const int MOD=1e9+7;
const int MAXN=1e6+5;

//infosys q1

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    map<char,int> map1;
    vector<int> v;
    string s;
    cin>>s;
    int c=0;
    for (int i = 0; i < s.size(); ++i) {
        if(i==0){
            map1[s[i]]=2;
            v.push_back(1);
        }
        else{
            if(map1[s[i]]>0)
                v.push_back(map1[s[i]]-1);
            else{
                if(c==1){
                    c=3;
                    map1[s[i]]=3;
                    v.push_back(2);
                }
                else{
                    map1[s[i]]=c+1;
                    v.push_back(c);
                    c++;
                }
            }
        }
    }
    ll ans=0;
    for (int i = 0; i < v.size(); ++i) {
        ans+=pow(map1.size(),v.size()-i-1)*v[i];
    }
    cout<<ans;
    return 0;
}
