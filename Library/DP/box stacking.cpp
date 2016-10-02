#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

ll a[50][3];

//Comparator to sort in order of decreasing base area
struct compare{
    bool operator()(const pair<int,pii > &p1 ,const pair<int,pii > &p2){
        return (p1.second.first*p1.second.second) > (p2.second.first*p2.second.second);
    }
};

ll solve(int n){
    vector<pair<int,pii > > v;
    for (int i = 0; i < n; ++i) {
        v.pb(mp(a[i][0],mp(max(a[i][1],a[i][2]), min(a[i][1],a[i][2]))));
        v.pb(mp(a[i][1],mp(max(a[i][2],a[i][0]), min(a[i][2],a[i][0]))));
        v.pb(mp(a[i][2],mp(max(a[i][0],a[i][1]), min(a[i][0],a[i][1]))));
    }

    sort(v.begin(),v.end(),compare());
    ll dp[v.size()];
    for (int i = 0; i < v.size(); ++i) {
        dp[i] = v[i].first;
    }

    for (int i = 1; i < v.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if(v[j].second.first > v[i].second.first &&
               v[j].second.second > v[i].second.second){
                dp[i] = max(dp[i], dp[j] + v[i].first);
            }
        }
    }

    ll result=0;
    for (int i = 0; i < v.size(); ++i) {
        result = max(result,dp[i]);
    }
    return result;
}

//http://www.spoj.com/problems/BABTWR/

int main() {
    Boost;
    int n;
    while(1){
        cin>>n;
        if(n==0)
            break;
        for (int i = 0; i < n; ++i) {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        cout<<solve(n)<<"\n";
    }
    return 0;
}