#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vpii investment;
int n, m;
bool check(ll mid) {
    ll total = 0;
    for (auto &[a, b]: investment) {
        total += max(0ll, b * mid - a);
    }
    return total >= m;
}

int solve(int tcase) {
    cin >> n >> m;
    investment.resize(n);
    for (auto &[a, b]: investment) cin >> b >> a;
    ll high = (m + investment[0].first) / investment[0].second + 10;
    ll low = 1;
    ll ans = high;
    while(low <= high) {
        ll mid = (high + low) / 2;
        if (check(mid)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}