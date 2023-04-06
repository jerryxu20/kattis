#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
    int n;
    cin >> n;
    vi dp(n + 2);
    dp[0] = 0;
    dp[1] = 1;
    int MOD = 1e6;
    for (int i = 2; i <= n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    cout << dp.back() << endl;
    return 0;
}