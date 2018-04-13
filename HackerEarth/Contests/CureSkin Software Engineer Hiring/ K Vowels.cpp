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


// 60/100 score


int main() {
    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0, j = 0, l = 0;
        int ans = 0;
        map<int,int> M;
        while (i <= j && j < n) {
            l=0;
            for(auto it:M){
                if(it.second)
                    l++;
            }
            if (l == k) {
                ans = max(ans, j - i);
//                cout<<j<<" "<<i<<"\n";
            }
            if (l <= k) {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                    M[s[j]]++;
                }
                j++;
            } else {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    M[s[i]]--;
                }
                i++;
            }
        }
        l=0;
        for(auto it:M){
            if(it.second)
                l++;
        }
        if (l == k) {
            if(j==s.size())
                ans = max(ans, j - i);
        }
        cout<<ans<<"\n";
    }

    return 0;
}