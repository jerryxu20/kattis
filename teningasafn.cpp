#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while(b) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return res;
}

ll fac[2000], inv[2000];
ll dp[2000];

ll choose(int n, int k) {
    return (((fac[n] * inv[k]) % MOD) * inv[n - k]) % MOD;
}

int main() {
    ll n, k; cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    
    fac[0] = 1;
    for (int i = 1; i <= k + 1; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    for (int i = 0; i <= k + 1; i++) {
        inv[i] = power(fac[i], MOD - 2);
    }

    std::function<ll(int n)> f = [&] (int p) {
        if (dp[p] != -1) return dp[p];
        if (p == 0) return (n % MOD);

        ll ans = power(n + 1, p + 1) - 1;
        for (int i = 0; i < p; i++) {
            ans -= (choose(p + 1, i) * f(i)) % MOD;
            ans %= MOD;
        }
        ans *= power(p + 1, MOD - 2);

        ans = ((ans % MOD) + MOD) % MOD;

        dp[p] = ans;
        return ans;
    };
    

    cout << f(k) << endl;
}