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
const int MAXN = 1e5+9;
const double TOLERANCE = 0.00000001;
const double PI = 3.14159265;


ld dist(ld x, ld y, ld u, ld v) {
    return sqrtl(((x - u) * (x - u)) + ((y - v) * (y - v)));
}

ld gettheta(ld x, ld y) {
    if (x > 0) {
        if (y > 0) {
            return acos(x / sqrtl((x * x) + (y * y)));
        }
        else {
            return (2 * PI) - acos(x / sqrtl((x * x) + (y * y)));
        }
    }
    else {
        if (y > 0) {
            return PI - acos(-x / sqrtl((x * x) + (y * y)));
        }
        else {
            return PI + acos(-x / sqrtl((x * x) + (y * y)));
        }
    }
}

bool check(ld x, ld y, ld u, ld v, ld r) {
    pair<ld, ld> lo = {x, y}, hi = {u, v};
    ld minDist;

    while (1) {
        pair<ld, ld> mid = {(lo.first + hi.first) / 2.0, (lo.second + hi.second) / 2.0};

        ld l = dist(lo.first, lo.second, 0.0, 0.0);
        ld h = dist(hi.first, hi.second, 0.0, 0.0);

        if (l - h < -TOLERANCE) {
            hi = mid;
        }
        else if (l - h > TOLERANCE) {
            lo = mid;
        }
        else {
            minDist = dist(mid.first, mid.second, 0.0, 0.0);
            break;
        }
    }


    if (minDist - r < -TOLERANCE)
        return 0;
    return 1;
}


int pointsToLine2(ld x, ld y, ld u, ld v, ld &m, ld &c) {
    if (fabsl(x - u) < TOLERANCE) {          // special case: vertical line
        m = inf;                    // l contains m = INF and c = x_value
        c = x;                  // to denote vertical line x = x_value
        return 0;   // we need this return variable to differentiate result
    }
    else {
        m = (y - v) / (x - u);
        c = y - m * x;
        return 1;     // l contains m and c of the line equation y = mx + c
    }
}


int main() {
    FastIO;
    ld x, y, u, v, r;
    cin >> x >> y >> u >> v >> r;

    ld ans = 0;

    if (check(x, y, u, v, r)) {
//        outside circle
//        cout<<"outside"<<"\n";
        ans = inf;

        for (ld i = 0.0; i <= 2.0 * PI; i += 0.00001) {
            ans = min(dist(r * cos(i), r * sin(i), x, y) + dist(r * cos(i), r * sin(i), u, v), ans);
        }
    }
    else {
//        inside the circle
//        cout<<"inside"<<"\n";

        ld m, c;
        if (pointsToLine2(x, y, u, v, m, c)) {
            ld l1 = dist(x, y, 0.0, 0.0), l2 = dist(u, v, 0.0, 0.0);
            ld angle1 = acosl(r / l1), angle2 = acosl(r / l2);
            ld arc = min(fabsl(gettheta(x, y) + angle1 - gettheta(u, v) - angle2),
                         fabsl(gettheta(x, y) - angle1 - gettheta(u, v) - angle2));
            arc = min(fabsl(gettheta(x, y) + angle1 - gettheta(u, v) + angle2), arc);
            arc = min(fabsl(gettheta(x, y) - angle1 - gettheta(u, v) + angle2), arc);

            ans += sqrtl((l1 * l1) - (r * r));
            ans += sqrtl((l2 * l2) - (r * r));
            ans += r * arc;
        }
        else {
            assert(1 == 2);
        }
    }

    cout << std::fixed << std::showpoint;
    cout << std::setprecision(6);
    cout << ans;
}