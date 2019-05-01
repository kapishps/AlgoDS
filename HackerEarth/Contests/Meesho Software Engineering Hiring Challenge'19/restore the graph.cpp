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

int m[109][109];

bool solve(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j && m[i][j] != 0)
                return 0;
            if(m[i][j] != m[j][i])
                return 0;
            for(int k=0;k<n;k++){
                if(m[i][k] > m[i][j] + m[j][k])
                    return 0;
            }
        }
    }
    return 1;
}

int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }
        if(solve(n))
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }

}