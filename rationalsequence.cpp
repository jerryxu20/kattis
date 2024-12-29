#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int tt; cin >> tt;
    char c;
    ll p, q; cin >> p >> c >> q;
    if (q == 1) {
        cout << tt << " " << 1 << "/" << p + 1 << endl;
        return;
    }

    pair<ll, ll> cur = {p, q};
    if (cur == make_pair(1LL, 1LL)) {
        cout << tt << " " << 1 << "/" << 2 << endl;
        return;
    }

    ll steps = 0;
    if (cur.first > cur.second) {
        steps = (cur.first - cur.second + cur.second - 1)/cur.second;
        cur.first -= steps * cur.second;
    } 
    cur.second -= cur.first;
    cur.first += cur.second;

    cur.second += cur.first * steps;
    cout << tt << " " << cur.first << "/" << cur.second << endl;

}

int main() {
    int t; cin >> t;
    while(t--) solve();
}