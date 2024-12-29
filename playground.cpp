#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n; cin >> n;
    if (n == 0) exit(0);
    vector<double> arr(n);
    for (double &x: arr) cin >> x;
    sort(arr.begin(), arr.end());

    double sm = 0;
    for (double &x: arr) {
        if (sm >= x) {
            cout << "YES\n";
            return 0;
        }
        sm += x;
    }
    cout << "NO\n";
    return 0;
}

int main() {
    while(true) {
        solve();
    }
    return 0;
}