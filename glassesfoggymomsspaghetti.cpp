#include <bits/stdc++.h>
using namespace std;


int main() {
    double d, x, y, h;
    cin >> d >> x >> y >> h;

    double t1 = atan(y/x) - atan((y-h/2)/x);
    double t2 = atan((y+h/2)/x) - atan(y/x);

    double ans = d * tan(t1) + d * tan(t2);
    cout << setprecision(20) << fixed << ans << endl;

}