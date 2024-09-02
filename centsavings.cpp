#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2001;
int price[MAXN];

int dp[MAXN][25][10];

int main() {
    int n, d; cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }


    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= d + 1; j++) {
            for (int m = 0; m < 10; m++) {
                dp[i][j][m] = 1e9;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d + 1; j++) {
            // add to existing group
            for (int m = 0; m < 10; m++) {
                dp[i][j][(m + price[i]) % 10] = min(dp[i][j][(m + price[i]) % 10], dp[i - 1][j][m] + price[i]);
            } 

            // create new group
            for (int m = 0; m <= 4; m++) {
                dp[i][j][price[i] % 10] = min(dp[i][j][price[i] % 10], dp[i - 1][j - 1][m] - m + price[i]);
            }
            for (int m = 5; m < 10; m++) {
                dp[i][j][price[i] % 10] = min(dp[i][j][price[i] % 10], dp[i - 1][j - 1][m] + (10 - m) + price[i]);
            }
        }
    }

    int ans = 1e9;
    for (int j = 1; j <= d + 1; j++) {
        for (int m = 0; m <= 4; m++) {
            dp[n][j][m] -= m;
            ans = min(ans, dp[n][j][m]);
        }
        for (int m = 5; m < 10; m++) {
            dp[n][j][m] += (10 - m);
            ans = min(ans, dp[n][j][m]);
        }
    }
    cout << ans << endl;


}