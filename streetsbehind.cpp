#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back

int solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    if (a == b) {
        cout << -1 << endl;
        return 0;
    }

    ll x = n;

    ll delta = b - a;
    ll ans = 0;
    ll z = (a + delta - 1)/delta;
    while(k > 0) {
        ll y = x * delta / a;
        if (y == 0) {
            cout << -1 << endl;
            return 0;
        }

        ll want = ((a * (y + 1)) + delta - 1)/delta;
        assert(want > x);

        ll cap = min(k, want - x);
        ll cycles = (cap + y - 1)/y;

        ans += cycles;
        x += y * cycles;
        k -= y * cycles;
        k = max(k, 0LL);
    }

    cout << ans << endl;
    return 0;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}