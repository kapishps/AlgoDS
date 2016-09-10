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

//infosys q2

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s="13#1,15,16,100,200";
    vector<int> v;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]-'0'>=0 && s[i]-'0'<=9){
            int a=0,n=i;
            while(s[n]-'0'>=0 && s[n]-'0'<=9){
                int b=s[n]-'0';
                a = (10*a)+b;
                n++;
            }
            v.push_back(a);
            i=n-1;
        }
    }
    sort(++v.begin(),v.end());
    ll dp[v.size()+1][2];
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }
    return 0;
}
