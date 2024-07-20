#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n, d; cin >> n >> d;

        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }

        ll cur = 1;
        for (int i = 1; ;i++) {
            if (cur <= n/(d + 1)) cur *= (d + 1);
            else {
                cout << i << endl;
                break;
            }
            if (cur >= n) {
                cout << i << "\n";
                break;
            }
        }
    }
}