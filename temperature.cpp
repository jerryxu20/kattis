#include <bits/stdc++.h>
using namespace std;


int main() {
    int x, y;
    cin >> x >> y;
    // x is the b temp when a is 0
    // y is how much a degree of a is equal to
    // A = yB + x = B
    int b = 1 - y;
    if (b == 0) {
        if (x == 0) {
            cout << "ALL GOOD";
        } else {
            cout << "IMPOSSIBLE";
        }
    } else {
        float ans = float(x) / float(b);
        cout << setprecision(7) << ans;
    }
    cout << '\n';
    return 0;
}