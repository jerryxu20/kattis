#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair

int logg(ll n) {
    int ans = 0;
    for (ll cur = 1; cur < n; cur *= 2) {
        ans++;
    }
    return ans;
}

int solve() {
    int n;
    cin >> n;
    vector<ll> size(n);
    ll log = logg(n);
    ll ans = 0;
    for (auto &s: size) {
        cin >> s;
        ans += s * log;
    }
    if (n == 1) {
        cout << size[0] << endl;
        return 0;
    }
    sort(all(size));
    while(__builtin_popcount(n) != 1) {
        n--;
        ans -= size.back();
        size.pop_back();
    }
    cout << ans << endl;
    assert(ans > 0);
    return 0;
}

int main() {
    int tcase = 1;
    cin >> tcase;
    for (int i = 1; i <= tcase; i++) {
        // cout << "Case #" << i << " : ";
        solve();
    }
    return 0;
}