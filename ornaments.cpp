#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    int r, h, s = 1;
    while (true) {
        cin >> r >> h >> s;
        if (r + h + s == 0) break;
        double factor = 1.0 + s / 100.0;
        double theta = M_PI / 2.0 - asin(double(r) / h);
        theta *= 2;
        double p = r * (2 * M_PI - theta);
        double t = 2 * sqrt(double(h * h) - double(r * r));
        double ans = p + t;
        ans *= factor;
        ans = round(ans * 100.0) / 100.0;
        cout << setprecision() << ans << endl;
    }
    return 0;
}