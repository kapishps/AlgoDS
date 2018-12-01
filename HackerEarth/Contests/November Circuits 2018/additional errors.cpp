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
const int MAXN = 5e3+9;


int main() {
    FastIO;
    int t;
    cin>>t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        int A[18] = {0}, B[18] = {0};
        ll sum = a+b;

        int i=0;
        while(a){
            A[i] = a%10;
            a /= 10;
            i++;
        }

        i= 0;
        while(b){
            B[i] = b%10;
            b /= 10;
            i++;
        }

        ll sum2 = 0;
        for (int j = 0; j < 18; ++j) {
            A[j] = (A[j] + B[j])%10;
            sum2 += powl(10,j)*A[j];
        }
        cout<<sum-sum2<<"\n";
    }

}