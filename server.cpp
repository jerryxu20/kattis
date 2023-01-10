#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, t;
    cin >> n >> t;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        t -= a;
        if (t < 0) {
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}