
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300;
const int MX = 1e9;
int dp[MAXN][MAXN];
int n;

int DP[13][1 << 13];

int f(int prev, int mask) {
    if (mask == 0) return dp[prev][0];

    int &ans = DP[prev][mask];
    if (ans != -1) return ans;

    ans = MX;
    for (int i = 0; i < n; i++) if (mask & (1 << i)) {
        int nmask = mask ^ (1 << i);
        ans = min(ans, dp[prev][i] + f(i, nmask));
    }
    return ans;
}

int main() {
    int v, m; cin >> n >> v >> m;

    memset(DP, -1, sizeof(DP));
    memset(dp, 60, sizeof(dp));

    while(m--) {
        int a, b, w; cin >> a >> b >> w;
        dp[a][b] = min(dp[a][b], w);
        dp[b][a] = min(dp[a][b], w);
    }

    for (int i = 0; i < v; i++) dp[i][i] = 0;

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                int cand = dp[i][k] + dp[k][j];
                dp[i][j] = min(dp[i][j], cand);
            }      
        }
    }

    cout << f(0, (1 << n) - 2) << endl;
}