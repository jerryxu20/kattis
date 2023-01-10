#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    int N, W;
    cin >> N >> W;
    vector<vector<int>> dp(W + 2, vector<int>(N + 1, -1));
    map<pair<int, int>, int> start;
    dp[0][N] = 0;
    int ans = 0;
    int mx = 0;
    for (int w = 1; w <= W + 1; w++) {
        int k;
        cin >> k;
        vector<pair<int, int>> sales (k);
        for (int i = 0; i < k; i++) {
            cin >> sales[i].first;
        }
        for (int i = 0; i < k; i++) {
            cin >> sales[i].second;
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= N; j++) {
                if (dp[w - 1][j] == -1) continue;
                int sold = min(j, sales[i].second);
                int left = j - sold;
                int cost = dp[w - 1][j] + sold * sales[i].first;
                dp[w][left] = max(cost, dp[w][left]);
                if (w == 1) {
                    start[mp(w, left)] = sales[i].first;
                } else if (cost == dp[w][left]) {
                    start[mp(w, left)] = start[mp(w - 1, j)];
                }
                ans = max(ans, dp[w][left]);
                if (dp[w][left] == ans) {
                    mx = start[mp(w, left)];
                }
            }
        }
    }
    cout << ans << endl;
    cout << mx << endl;
    return 0;
}