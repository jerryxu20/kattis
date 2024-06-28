#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m; cin >> m;
    
    vector<int> dis(m);
    for (int &x: dis) cin >> x;

    vector<vector<int>> dp(m + 1, vector<int>(1001, 2000));
    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        int x = dis[i - 1];
        for (int j = 0; j <= 1000; j++) {
            if (j - x >= 0) {
                dp[i][j] = min(dp[i][j], max(j, dp[i - 1][j - x]));
            }

            if (j + 1 <= 1000) {
                dp[i][j] = min(dp[i][j], max(j, dp[i - 1][j + x]));
            }
        }
    }
    
    int cur = 0;
    if (dp.back()[0] > 1000) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int j = m;
    string ans;
    do {
        int x = dis[j - 1];
        if (cur - x >= 0 && dp[j - 1][cur - x] <= dp[j][cur]) {
            ans.push_back('U');
            cur = cur - x;
        } else {
            ans.push_back('D');
            cur = cur + x;
        }
        j--;
    } while (j > 0);

    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return;

}


int main() {
    int n; cin >> n;
    while(n--) {
        solve();
    }
}