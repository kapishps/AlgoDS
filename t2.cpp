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
const int MAXN = 1e5+9;

int main() {
//    Boost;
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    cout<<0<<" ";
    for (int i = 1; i <=n; ++i) {
        a[i] = i^a[i-1];
        cout<<a[i]<<" ";
    }
    return 0;
}
