#include <bits/stdc++.h>
using namespace std;

void solve() {
    int h, c; cin >> h >> c;
    vector<double> X(h);
    for (auto &x: X) cin >> x;

    vector<vector<double>> cost(h, vector<double>(h));
    for (int i = 0; i < h; i++) {
        for (int j = i + 1; j < h; j++) {
            double delta = 0;
            for (int k = i; k <= j; k++) {
                double pos = X[i] + (X[j] - X[i]) * (double)(k - i)/(j - i);
                delta += abs(pos - X[k]);
            }
            cost[i][j] = delta;
        }
    }

    vector<vector<double>> dp(h, vector<double>(c + 1, 1e9));
    dp[0][1] = 0;

    for (int r = 1; r < h; r++) {
        for (int k = 2; k <= c; k++) {
            for (int l = 0; l < r; l++) {
                double cand = dp[l][k - 1] + cost[l][r];
                dp[r][k] = min(dp[r][k], cand);
            }
        }
    }
    cout << setprecision(15) << fixed << dp[h - 1][c]/h << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}