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

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;



int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        vector<int> Mx,My,Mz;
        for (int i = 1; i <=sqrt(n)+1; ++i) {
            if(n%i==0) {
                if (n/i == i){
                    if(i <= a)
                        Mx.push_back(i);
                    if(i <= b)
                        My.push_back(i);
                    if(i <= c)
                        Mz.push_back(i);
                }

                else {
                    if(i <= a)
                        Mx.push_back(i);
                    if(i <= b)
                        My.push_back(i);
                    if(i <= c)
                        Mz.push_back(i);
                    if(n/i <= a)
                        Mx.push_back(n/i);
                    if(n/i <= b)
                        My.push_back(n/i);
                    if(n/i <= c)
                        Mx.push_back(n/i);
                }
            }
        }
        sort(Mx.begin(),Mx.end());
        sort(My.begin(),My.end());
        sort(Mz.begin(),Mz.end());
        for(auto i : Mx){
            for(auto j : My){
                if(n/i <=b && )
                    for(auto k : Mz){

                    }
            }
        }

    }

    return 0;
}