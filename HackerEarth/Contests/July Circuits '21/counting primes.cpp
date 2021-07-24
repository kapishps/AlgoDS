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

int x[MAXN], y[MAXN];
int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73 , 79, 83, 89, 97};

int solve(int n, int i, int v) {
    int cnt = 0;
    for(int j =0; j < 25; j++){
        if(x[i]%primes[j] == 0){
            for(int k = i-v; k < i; k++){
                if(x[k]%primes[j] == 0){
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt;
}

int main() {
    FastIO;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
        cout<<solve(n,i,y[i])<<" ";
    }

}