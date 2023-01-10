#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    int q = 1;
    while (cin >> n) {
        int mx;
        cin >> mx;
        int mn = mx;
        for (int i = 1; i < n; i++) {
            int a;
            cin >> a;
            mx = max(mx, a);
            mn = min(mn, a);
        }
        cout << "Case " << q << ": " << mn << ' ' << mx << ' ' << mx - mn << '\n';
        q++;

    }
    return 0;
}