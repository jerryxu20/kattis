#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pi;

double dis(const pi &a, const pi &b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return dx * dx + dy * dy;
}

int main() {
    int l, w, n, r;
    cin >> l >> w >> n >> r;

    
    vector<int> st(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (dis({x, y}, {-l/2.0, 0}) <= r * r) st[i] |= 1;
        if (dis({x, y}, {l/2.0, 0}) <= r * r)  st[i] |= 2;
        if (dis({x, y}, {0, -w/2.0}) <= r * r) st[i] |= 4;
        if (dis({x, y}, {0, w/2.0}) <= r * r)  st[i] |= 8;
        cur |= st[i];
    }
    if (cur != 15) {
        cout << "Impossible\n";
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(16, 100));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 16; j++) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = min(dp[i][j], dp[i - 1][j & ~st[i - 1]] + 1);
        }
    }
    cout << dp.back().back() << endl;
}