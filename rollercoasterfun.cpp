#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAXT = 25005;

typedef pair<int, int> pi;

int dp[MAXT];

int A[MAXN], B[MAXN], T[MAXN];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> T[i];
    }

    vector<pi> rides;
    for (int i = 0; i < n; i++) if (B[i] > 0) {
        for (int k = 0; ; k++) {
            int fun = A[i] - k * k * B[i];
            if (fun <= 0) break;

            rides.push_back({fun, T[i]});
        }
    }

    for (auto &[val, weight]: rides) {
        for (int i = MAXT - 1; i >= 0; i--) if (i - weight >= 0) {
            dp[i] = max(dp[i], dp[i - weight] + val);
        }
    }

    for (int i = 0; i < n; i++) if (B[i] == 0) {
        for (int j = 0; j < MAXT; j++) if (j - T[i] >= 0) {
            dp[j] = max(dp[j], dp[j - T[i]] + A[i]);
        }
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << dp[x] << "\n";
    }
}