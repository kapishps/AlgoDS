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
//    FastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans[n + 1], Xor[n + 1], i = 1;
        ll x;
        while (n - i + 1 >= 8) {
            cout << 1 << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
            fflush(stdout);
            cin >> Xor[i];
            cout << 1 << " " << i << " " << i + 2 << " " << i + 3 << "\n";
            fflush(stdout);
            cin >> Xor[i + 1];
            cout << 1 << " " << i << " " << i + 1 << " " << i + 3 << "\n";
            fflush(stdout);
            cin >> Xor[i + 2];
            cout << 1 << " " << i << " " << i + 1 << " " << i + 2 << "\n";
            fflush(stdout);
            cin >> Xor[i + 3];

            x = Xor[i] ^ Xor[i + 1] ^ Xor[i + 2] ^ Xor[i + 3];
            for (int j = 0; j < 4; j++) {
                ans[i + j] = x ^ Xor[i + j];
            }
            i += 4;
        }

        if (n - i +1 == 4) {
            cout << 1 << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
            fflush(stdout);
            cin >> Xor[i];
            cout << 1 << " " << i << " " << i + 2 << " " << i + 3 << "\n";
            fflush(stdout);
            cin >> Xor[i + 1];
            cout << 1 << " " << i << " " << i + 1 << " " << i + 3 << "\n";
            fflush(stdout);
            cin >> Xor[i + 2];
            cout << 1 << " " << i << " " << i + 1 << " " << i + 2 << "\n";
            fflush(stdout);
            cin >> Xor[i + 3];

            x = Xor[i] ^ Xor[i + 1] ^ Xor[i + 2] ^ Xor[i + 3];
            for (int j = 0; j < 4; j++) {
                ans[i + j] = x ^ Xor[i + j];
            }
        } else if (n - i + 1 == 5) {
            cout << 1 << " " << i << " " << i + 1 << " " << i + 2 << "\n";
            fflush(stdout);
            cin >> Xor[i];
            cout << 1 << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
            fflush(stdout);
            cin >> Xor[i + 1];
            cout << 1 << " " << i + 2 << " " << i + 3 << " " << i + 4 << "\n";
            fflush(stdout);
            cin >> Xor[i + 2];
            cout << 1 << " " << i + 3 << " " << i + 4 << " " << i << "\n";
            fflush(stdout);
            cin >> Xor[i + 3];
            cout << 1 << " " << i + 4 << " " << i << " " << i + 1 << "\n";
            fflush(stdout);
            cin >> Xor[i + 4];

            x = Xor[i] ^ Xor[i + 1] ^ Xor[i + 2] ^ Xor[i + 3] ^ Xor[i + 4];
            for (int j = 0; j < 5; j++) {
                ans[i + j] = x ^ Xor[i + j] ^ Xor[i + (j + 3) % 5];
            }
        } else if (n - i +1 == 6) {
            int a = i, b = i + 1, c = i + 2, d = i + 3, e = i + 4, f = i + 5;
            int abc, bcd, ade, adf, efb, efc;
            cout << 1 << " " << a << " " << b << " " << c << "\n";
            fflush(stdout);
            cin >> abc;
            cout << 1 << " " << b << " " << c << " " << d << "\n";
            fflush(stdout);
            cin >> bcd;
            cout << 1 << " " << a << " " << d << " " << e << "\n";
            fflush(stdout);
            cin >> ade;
            cout << 1 << " " << a << " " << d << " " << f << "\n";
            fflush(stdout);
            cin >> adf;
            cout << 1 << " " << e << " " << f << " " << b << "\n";
            fflush(stdout);
            cin >> efb;
            cout << 1 << " " << e << " " << f << " " << c << "\n";
            fflush(stdout);
            cin >> efc;

            ans[i + 4] = abc ^ bcd ^ ade;
            ans[i + 5] = abc ^ bcd ^ adf;
            ans[i + 1] = efb ^ ans[i + 4] ^ ans[i + 5];
            ans[i + 2] = efc ^ ans[i + 4] ^ ans[i + 5];
            ans[i] = abc ^ ans[i + 1] ^ ans[i + 2];
            ans[i + 3] = bcd ^ ans[i + 1] ^ ans[i + 2];
        }
        else {
            cout << 1 << " " << i << " " << i + 1 << " " << i + 2 << "\n";
            fflush(stdout);
            cin >> Xor[i];
            cout << 1 << " " << i + 1 << " " << i + 2 << " " << i + 3 << "\n";
            fflush(stdout);
            cin >> Xor[i + 1];
            cout << 1 << " " << i + 2 << " " << i + 3 << " " << i + 4 << "\n";
            fflush(stdout);
            cin >> Xor[i + 2];
            cout << 1 << " " << i + 3 << " " << i + 4 << " " << i + 5 << "\n";
            fflush(stdout);
            cin >> Xor[i + 3];
            cout << 1 << " " << i + 4 << " " << i + 5 << " " << i + 6 << "\n";
            fflush(stdout);
            cin >> Xor[i + 4];
            cout << 1 << " " << i << " " << i + 5 << " " << i + 6 << "\n";
            fflush(stdout);
            cin >> Xor[i + 5];
            cout << 1 << " " << i << " " << i + 1 << " " << i + 6 << "\n";
            fflush(stdout);
            cin >> Xor[i + 6];

            x = Xor[i] ^ Xor[i + 1] ^ Xor[i + 2] ^ Xor[i + 3] ^ Xor[i + 4] ^ Xor[i + 5] ^ Xor[i + 6];
            for (int j = 0; j < 7; j++) {
                ans[i + j] = x ^ Xor[i + (j+1)%7]^ Xor[i + (j+4)%7];
            }
        }

        cout<<2<<" ";
        fflush(stdout);
        for (int j = 1; j <= n; ++j) {
            cout << ans[j] << " ";
            fflush(stdout);
        }
        cout << "\n";
        fflush(stdout);
        cin >> i;
    }
    return 0;
}

//{6 8 9 12 5 645 865 221}
//1
//8
//13
//3
//2
//7
//313
//953
//605
//481

//{645,865,221,76,644,32,56}
//1
//7
//313
//1008
//533
//744
//668
//669
//476
//2

//{645,865,676,644,32,56}
//1
//6
//832
//833
//33
//57
//889
//700


//{645,865,676,644,32}
//1
//5
//832
//833
//0
//33
//452
