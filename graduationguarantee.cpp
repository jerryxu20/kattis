#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5001;
double dp[MAXN][MAXN * 2];
double prob[MAXN];

int main() {
    int n, k; cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> prob[i];
    }

    sort(prob + 1, prob + n + 1, greater<double>());
    dp[0][n] = 1;

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        double p = prob[i];
        double cand = 0;
        for (int j = 0; j <= 2 * n; j++) {
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * p;
            }
            if (j < 2 * n) {
                dp[i][j] += dp[i - 1][j + 1] * (1 - p);
            }

            if (j >= n + k) cand += dp[i][j];
        }
        ans = max(ans, cand);
    }
    cout << fixed << setprecision(15) << ans << endl;
}