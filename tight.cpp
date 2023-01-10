#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

ll backtrack(int length, int k, int last) {
    if (length == 0) return 1;
    ll ans = 0;
    for (int i = max(0, last - 1); i <= min(last + 1, k); i++) {
        ans += backtrack(length - 1, k, i);
    }
    return ans;
}

ll dp(int n, int k) {
    if (k == 0) return n;
    if (k == 1) {
        return 1 << n;
    }
    // there are k digits
    // I want something that is length n
    vector<vector<ll>> dp(n, vector<ll> (k));
    for (int i = 0; i < k; i++) {
        dp[0][i] = 1;
    } 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j + 1 < k) {
                dp[i][j] += dp[i - 1][j + 1];
            }
        }
    }
    ll ans = 0;
    for (ll num: dp.back()) {
        ans += num;
    }
    return ans;
}

int main() {
    int n, k;
    while (cin >> k >> n) {
        if (k <= 1) {
            cout << 100 << endl;
            continue;
        }
        ll valid = dp(n, k + 1);
        double ans = valid  * 100;
        while (n--) {
            ans /= (k + 1);
        }
        cout << fixed << setprecision(12) <<  ans << endl;

    }
    return 0;
}