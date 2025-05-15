#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X, Y; cin >> X >> Y;
    ll ans = 0;
    for (ll a = 1; a < 64; a++) {

        ll aa = (1LL << a) - 1;
        if (aa >= X && aa <= Y) {
            ans++;
        }

        for (ll b = 1; a + b < 64; b++) {
            ll cur = aa << b;
            ll bits = a + b;

            int i = 0;
            while(bits < 64) {
                // check 
                if (cur >= X && cur <= Y) {
                    ans++;
                }
                if (i) {
                    // add B
                    cur <<= b;
                    bits += b;
                } else {
                    // add A
                    cur <<= a;
                    cur += aa;
                    bits += a;
                }
                i ^= 1;
            }
        }
    }

    cout << ans << endl;
}