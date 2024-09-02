#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, r, p;

const int MAXN = 1e6 + 1;
ll dp[MAXN];

ll f(ll x) {
    if (x <= 1) return 0;
    if (dp[x] != -1) return dp[x];
    ll ans = 1e15;
    for (ll part = 1; part <= x; part++) {
        ll rem = (x + part)/(part + 1);
        ans = min(ans, part * p + r + f(rem));
    }
    dp[x] = ans;
    return ans;
}


int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> r >> p;
    cout << f(n) << endl;
}