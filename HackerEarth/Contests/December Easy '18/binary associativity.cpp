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

int arr[MAXN];

int main() {
    FastIO;
    int t;
    cin>>t;
    int tt[2][2];
    while(t--){
        cin>>tt[0][0]>>tt[0][1]>>tt[1][0]>>tt[1][1];
        int flag = 1;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    if(tt[i][tt[j][k]] != tt[tt[i][j]][k]){
                        flag = 0;
                    }
                }
            }
        }
        if(flag == 0){
            cout<<"No"<<"\n";
        } else
            cout<<"Yes"<<"\n";

    }

}