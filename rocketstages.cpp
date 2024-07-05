#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1001;
const int MAXW = 10001;
ll mass[MAXN], fuel[MAXN], up[MAXN], cons[MAXN];
double dp[MAXN][MAXW];

int main() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> mass[i] >> fuel[i] >> up[i] >> cons[i];
    }

    double ans = 0;
    for (int i = 1; i <= n; i++) {

        int W = mass[i] + fuel[i];
        
        for (int j = 0; j <= MAXW; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j < W) continue;
            double acc = (up[i] - 9.8 * j) / j;
            if (acc < 0) continue;

            double t = (double)fuel[i]/cons[i];
            double cont = -(double)up[i]/cons[i] * log(j - cons[i] * t) - 9.8 * t + (double)up[i]/cons[i] * log(j);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - W] + cont);
            ans = max(ans, dp[i][j]);
        }
    }

    cout << (ll)round(ans) << endl;
}