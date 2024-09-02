#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 500;
ll price[MAXN];


int main() {
    // dp[i]: most money in days 0..i
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> price[i];


    vector<ll> dp(n + 1);
    dp[0] = 100;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 1; j < n; j++) if (price[j] < price[i]) {
            ll cnt = dp[j]/price[j];
            cnt = min(cnt, 100000LL);
            dp[i] = max(dp[i], dp[j] + cnt * (price[i] - price[j]));
        }
    }

    cout << dp.back() << endl;
}