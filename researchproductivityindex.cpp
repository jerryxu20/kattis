#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ac(n);
    for (int &x: ac) cin >> x;

    sort(ac.begin(), ac.end(), greater<int>());

    double ans = 0;
    vector<int> papers;

    vector<vector<double>> dp(n + 1, vector<double>(n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            double p = ac[i - 1]/100.0;
            if (j > 0) dp[i][j] += dp[i - 1][j - 1] * p;
            dp[i][j] += dp[i - 1][j] * (1 - p);
        }
    }
    

    for (int sub = 1; sub <= n; sub++) {

        double cand = 0;
        for (int hit = 0; hit <= sub; hit++) {
            double prob = dp[sub][hit];
            double score = hit == 0 ? 0: pow(hit, (double)hit/sub);

            cand += prob * score;
        }
        ans = max(ans, cand);        
    }
    cout << setprecision(10) << fixed << ans << endl;


}