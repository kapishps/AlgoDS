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

int main() {
    FastIO;
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> minh;
    priority_queue<int> maxh;
    int i = 1;
    while (n--) {
        int o;
        cin >> o;
        if (o == 1) {
            int x;
            cin >> x;

            maxh.push(x);

            if (!minh.empty() && minh.top() < maxh.top()) {
                maxh.push(minh.top());
                minh.pop();
                minh.push(maxh.top());
                maxh.pop();
            }

            if (i % 3 == 0) {
                minh.push(maxh.top());
                maxh.pop();
            }

            i++;
        }
        else {
            if (i <= 3)
                cout << "Not enough enemies\n";
            else
                cout << minh.top() << "\n";
        }
    }
}