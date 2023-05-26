#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
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

int solve(int tcase) {
    int n, a, b;
    cin >> n >> a >> b;
    vi dp(n + 1, int(1e6) + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= a) dp[i] = min(dp[i], dp[i - a] + 1);
        if (i >= b) dp[i] = min(dp[i], dp[i - b] + 1);
    }
    if (dp[n] >= int(1e6) + 1) {
        cout << "Impossible\n";
    }
    for (int i = 0; i <= dp[n]; i++) {
        if (i * a + b * (dp[n] - i) == n) {
            cout << i << " " << dp[n] - i << endl;
            return 0;
        }
    }
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