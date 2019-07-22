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
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e6+9;

vector<int> arr;

//int solve(int a[],int n) {       // O(n^2) DP Solution
//    int dp[n];
//    for (int i = 0; i < n; ++i) {
//        dp[i] = 1;
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < i; ++j) {
//            if (a[j] < a[i])
//                dp[i] = max(dp[i], dp[j] + 1);
//        }
//    }
//    int ans = 0;
//    for (int i = 0; i < n; ++i) {
//        ans = max(ans, dp[i]);
//    }
//    return ans;
//}

//https://www.hackerrank.com/challenges/longest-increasing-subsequent/problem

int bs_lower_bound(int n, int key) {
    int mid;
    int lo = 0, hi = n ;
    while (hi > lo) {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] >= key)
            hi = mid;
        else
            lo = mid + 1;
    }

    return lo;
}

int main() {
    FastIO;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {       // O(nlogn) solution
        int x;
        cin>>x;
//        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int idx = bs_lower_bound(arr.size(), x);
        if (idx == arr.size())
            arr.push_back(x);
        else
            arr[idx] = x;
    }
    cout<<arr.size();
    return 0;
}