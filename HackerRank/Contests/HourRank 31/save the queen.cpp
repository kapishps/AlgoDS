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
const double TOLERANCE = 0.00001;



int main() {
    FastIO;
    int n,k;
    cin>>n>>k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());

    vector<double> soldiers;
    double ans =inf,sum =0;
    for (int i = 0; i < k; ++i) {
        if(i<n) {
            soldiers.push_back((double)a[i]);
            ans = min(ans, (double) a[i]);
        }
        else{
            sum += a[i];
        }
    }

    if(sum != 0) {
        double lo = 0, hi = 2e12+9;
        while (1) {
            double mid = (lo + hi) / 2.0;
            double x = sum;
            for (int i = 0; i < soldiers.size(); ++i) {
                if (mid - soldiers[i] > TOLERANCE) {
                    x -= mid - soldiers[i];
                }
            }
            if (x < -TOLERANCE) {
                hi = mid;
            }
            else if (x > TOLERANCE) {
                lo = mid;
            }
            else {
                ans = mid;
                break;
            }
        }
    }


    cout << std::fixed << std::showpoint;
    cout << std::setprecision(4);
    cout << ans;

}