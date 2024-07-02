#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t lll;

int main() {
    ll x, y; cin >> x >> y;

    ll dx = x/gcd(x, y);
    ll dy = y/gcd(x, y);

    if (dx == x && dy == y) {
        cout << "Yes\n";
        return 0;
    }

    pair<ll, ll> rx, ry;
    cin >> rx.first >> ry.first >> rx.second >> ry.second;
    
    if (dx > rx.second || dx < rx.first) {
        cout << "No\n";
        cout << dx << " " << dy << endl;
        return 0;
    }

    if (dy > ry.second || dy < ry.first) {
        cout << "No\n";
        cout << dx << " " << dy << endl;
        return 0;
    }

    ll low = 1;
    ll high = 1e12;
    ll mag = -1;

    while(low <= high) {
        lll mid = (low + high)/2;
        lll X = dx * mid;
        lll Y = dy * mid;

        if (X > rx.second || Y > ry.second) {
            high = mid - 1;
            mag = mid;
        } else {
            low = mid + 1;
        }
    }

    if (mag == -1 || dx * mag >= x || dy * mag >= y) {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    cout << dx * mag << " " << dy * mag << endl;
}