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

/*
10
4 3 7 5 10
5 1 5 10 6 4
4 7 5 9 4
0
2 9 4
2 9 4
2 5 4
6 1 3 7 10 6 4
1 4
1 9
2 1 3 7 5 2 4 1 6 3
*/

int main() {
    int n;
    cin>>n;
    vector<int> a[309];
    map<int,int> map1;
    for (int i = 1; i <=n; ++i) {
        int m;
        cin>>m;
        for (int j = 0; j < m; ++j) {
            int x;
            cin>>x;
            map1[x]++;
            a[i].push_back(x);
        }
    }
    int count =1;
    int b[500] = {0};
    while(1){
        vector<int> rem;
        for (int i = 1; i <=n; ++i) {
            if(map1[i]==0){
                rem.push_back(i);
                b[i] = count;
                map1[i]=-1;
            }
        }
        if(rem.size()==0)
            break;
        for (int i = 0; i < rem.size(); ++i) {
            for (int j = 0; j < a[rem[i]].size(); ++j) {
                map1[a[rem[i]][j]]--;
            }
        }
        count++;
    }
    for (int i = 1; i <=n; ++i) {
        cout<<b[i]<<" ";
    }
    return 0;
}
