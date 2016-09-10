#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

const int MOD=1e9+7;
const int MAXN=1e6+10;

long long ways[MAXN];

int solve(int n){
    for (int i = 4; i < n; ++i) {
        ways[i] = (ways[i-1] + ((i-1)*ways[i-2])%MOD)%MOD;
    }
    return 1;
}

//https://www.hackerearth.com/code-monk-dynamic-programming/algorithm/vibhu-and-his-mathematics/

int main() {
    int t;
    cin>>t;
    ways[0]=0;
    ways[1]=1;
    ways[2]=2;
    ways[3]=4;
    solve(1000008);
    while (t--){
        int n;
        cin>>n;
        cout<<ways[n]<<endl;
    }
    return 0;
}
