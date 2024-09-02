#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(ll x, vector<ll> arr, ll d) {
    ll mx = 0;
    ll mn = LLONG_MAX;
    for (auto &k: arr) {
        ll need = max(0LL, x - k);
        d -= need;
        k += need;

        mn = min(mn, k);
        mx = max(mx, k);
    }

    if (d < 0) return -1;

    for (auto &k: arr) if (k == mx) {
        k += d;
        break;
    }

    ll ans = 0;
    for (auto &k: arr) {
        ans += k * k;
    }
    ans += 7 * mn;
    return ans;
}


void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;

    ll low = 0;
    ll high = 2e9;
    ll ans = 0;
    while(low <= high) {

        if (high - low <= 1e6) {
            for (ll i = low; i <= high; i++) {
                ans = max(ans, calc(i, {a, b, c}, d));
            }
            break;
        }

        ll l = low + (high - low)/3;
        ll r = high - (high - low)/3;

        

        ll A = calc(l, {a, b, c}, d);
        ll B = calc(r, {a, b, c}, d);

        ans = max({ans, A, B});

        if (A == -1) {
            high = l - 1;
            continue;
        }
        if (B == -1) {
            high = r - 1;
            continue;
        }
        ans = max({ans, A, B});

        if (A > B) {
            high = r - 1;
        } else {
            low = l + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    int n; cin >> n;
    while(n--) solve();
}