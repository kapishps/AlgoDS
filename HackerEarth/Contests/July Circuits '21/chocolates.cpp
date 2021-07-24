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
int cnt =0;
map<pii, int> map1;

bool solve(int start, int end, int k){
    if(start == end){
        return 1;
    }
    if(start > end){
        return 0;
    }
    if(map1[{start,end}] > 0){
        return map1[{start,end}]%2;
    }
    int ans = 0;
    if(arr[start] == arr[end]){
        for(int i= start+k; i >= start+1; i--){
            for(int j = end-k; j <= end-1; j++){
                if(arr[i] == arr[j]){
                    ans |= solve(i, j, k);
                }
                if(ans){
                    map1[{start,end}] = 1;
                    return ans;
                }
            }
        }
    }
    map1[{start,end}] = 2;
    return ans;
}

int main() {
    FastIO;
    int n, k;
    cin>>n>>k;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    if(solve(0, n-1, k)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}