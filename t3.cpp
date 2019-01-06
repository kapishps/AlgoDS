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


string solve(int n){
    n++;
    string t;
    while(n>=2){
        t += to_string(n%2);
        n/=2;
    }

    string ans;
    for (int i = t.size()-1; i >= 0; i--) {
        if(t[i] == '1')
            ans += "7";
        else
            ans += "4";
    }
    return ans;
}

void printSet(int vS) {                         // in binary representation
//    printf("S = %2d = ", vS);
    stack<int> st;
    while (vS)
        st.push(vS % 2), vS /= 2;
    while (!st.empty())                         // to reverse the print order
        cout<<st.top(),st.pop();
//    printf("\n");
}

int main() {
    FastIO;
    for (int i = 1; i < 100; ++i) {
        printSet(i+1);
        cout<<" "<<solve(i)<<"\n";

    }
    cout<<"\n"<<solve(30);
    return 0;
}