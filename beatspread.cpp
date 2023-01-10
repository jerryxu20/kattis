#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b > a) {
            cout << "impossible" << '\n';
            continue;
        }
        int x = (a - b);
        if (x % 2 == 1) {
            cout << "impossible" << '\n';
            continue;
        }
        x /= 2;
        cout << x << ' ' << a - x << '\n';
    }
    return 0;
}