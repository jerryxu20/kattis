#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int tcase) {
    double r, x, y;
    while(cin >> r >> x >> y) {
        if (x * x + y * y >= r * r) {
            cout << "miss\n";
            continue;
        }
        double l = sqrt(x * x + y * y);
        double height = r - l;
        double theight = r - height;
        double angle = acos(theight / r);
        double width = r * sin(angle);
        double cone = r * r * angle;
        double area = cone - (theight * width);
        double area2 = M_PI * r * r - area;
        // cout << "height " << height << " angle " << angle << " width " << width << " theight " << theight << endl;
        cout << setprecision(10) << fixed << max(area, area2) << " " << min(area, area2) << endl;
    }


    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    // for (int i = 1; i <= testcase; i++) {
        // solve(i);
    // }
    solve(1);
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}