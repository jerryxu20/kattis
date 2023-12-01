#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
int x, y;
double check(double m) {
    double b = y - 2 * m;
    double a = x - 2 * m;
    if (a <= 0 || b <= 0) return -1;

    return a * b * m;
}

int solve(int tt) {
    cin >> x >> y;

    double low = 0;
    double high = x;
    double ans = 0;
    while(abs(high - low) > EPS) {
        double m1 = (high - low)/3 + low;
        double m2 = 2 * (high - low)/3 + low;
        double a1 = check(m1);
        double a2 = check(m2);
        ans = max({ans, a1, a2});
        if (a1 <= 0) {
            high = m2;
            continue;
        }

        if (a1 > a2) {
            high = m2;
        } else {
            low = m1;
        }
    }
    cout << fixed << setprecision(20) << ans << endl;

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}