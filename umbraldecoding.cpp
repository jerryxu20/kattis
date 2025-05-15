#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;

int main() {
    ll n, k; cin >> n >> k;

    vector<tuple<ll, ll, ll>> pts(k);
    for (auto &[x, y, b]: pts) cin >> x >> y >> b;

    map<ll, vector<pair<ll, ll>>> intervals;

    for (auto &[x, y, b]: pts) {

        ll delta = (ll)cbrt(b) + 1;
        for (ll i = y - delta; i <= y + delta; i++) if (i >= 0 && i <= n) {
            // for each row, what is bad?
            ll dy = abs(i - y);
            ll rem = b - abs(dy * dy * dy);
            if (rem < 0) continue;

            ll dx = (ll)cbrt(rem);

            if ((dx + 1) * (dx + 1) * (dx + 1) <= rem) dx++;
            if (dx * dx * dx > rem) dx--;
            intervals[i].push_back({max(x - dx, 0LL), min(x + dx, n)});
        }
    }
    lll ans = (lll)(n + 1) * (n + 1);
    for (auto &[_, arr]: intervals) {
        sort(arr.begin(), arr.end());

        ll high = LLONG_MIN;
        ll cnt = 0;

        for (auto &[l, r]: arr) {
            if (high >= l) {
                cnt += max(r, high) - high;
            } else {
                cnt += r - l + 1;
            }

            high = max(high, r);
        }
        ans -= cnt;
    }

    string res;
    while(ans) {
        res += '0' + (ans % 10);
        ans /= 10;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

}