#include <bits/stdc++.h>
using namespace std;


const int MAXN = 5005;
vector<pair<int, int>> special[MAXN];
int cnt[MAXN], arr[MAXN], cost[MAXN];
int main() {
    int n, k, s; cin >> n >> k >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];


    for (int i = 0; i < k; i++) {
        int tot = 0;
        for (int j = i; j < n; j += k) {
            cnt[arr[j]]++;
            tot++;
        }

        cost[i] = tot;


        for (int j = i; j < n; j += k) {
            if (cnt[arr[j]]) {
                special[i].push_back({arr[j], tot - cnt[arr[j]]});
                cnt[arr[j]] = 0;
            }
        }
    }

    vector<vector<int>> dp(k + 1, vector<int>(s + 1, n));
    dp[0][0] = 0;

    for (int i = 1; i <= k; i++) {
        int mn = n;
        for (int j = 0; j <= s; j++) {
            mn = min(mn, dp[i - 1][j]);
            dp[i][j] = mn + cost[i - 1];
        }

        for (int j = 0; j <= s; j++) {
            for (auto &[val, c]: special[i - 1]) if (j >= val) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - val] + c);
            }
        }
    }

    cout << dp.back().back() << endl;
}
