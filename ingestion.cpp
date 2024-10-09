#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
int arr[MAXN], eat[MAXN];
int dp[MAXN][60];
int main() {
    int n, m; cin >> n >> m;
    eat[0] = m;
    for (int i = 1; i < MAXN; i++) {
        eat[i] = (eat[i - 1] * 2)/3;
        if (eat[i] == 0) break;
    }
    for (int i = 3; i <= n + 2; i++) cin >> arr[i];

    for (int i = 3; i <= n + 2; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                if (k <= j) {
                    dp[i][k] = max(dp[i][k], dp[i - 3][j] + min(eat[k], arr[i]));
                }
                if (k == j) {
                    dp[i][k] = max(dp[i][k], dp[i - 2][j] + min(eat[k], arr[i]));
                }
                if (k > j) {
                    dp[i][k] = max(dp[i][k], dp[i - 1][j] + min(eat[k], arr[i]));
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n + 2; i++) {
        for (int j = 0; j < 60; j++) {
            ans = max(ans, dp[i][j]);
        } 
    }
    cout << ans << endl;

}