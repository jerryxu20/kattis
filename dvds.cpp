#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int cur[MAXN], at[MAXN];
int mn[MAXN], dp[MAXN];


void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cur[i]; cur[i]--;
        at[cur[i]] = i;
    }


    int m = n;
    for (int i = n - 1; i >= 0; i--) {
        mn[i] = m;
        m = min(m, cur[i]);
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 0;
        if (i > 0) dp[i] += dp[i - 1];
        if (mn[at[i]] < i || (i > 0 && dp[i - 1])) {
            dp[i]++;
        }
    }
    cout << dp[n - 1] << endl;

}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T; cin >> T;
    while(T--) solve();
}
