#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, k, q; cin >> n >> k >> q;

    while(q--) {
        ll a, b; cin >> a >> b;
        a--; b--;

        if (k == 1) {
            cout << abs(a - b) << "\n";
            continue;
        }

        int ans = 0;
        while(a != b) {
            if (a > b) {
                a--;
                a /= k;
            } else {
                b--;
                b /= k;
            }
            ans++;
        }

        cout << ans << endl;


    }

}