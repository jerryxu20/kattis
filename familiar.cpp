#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A, B, k;

int MOD = 1e9 + 7;

ll inv[11];

vector<int> upper, lower;

ll dp[20][2][1 << 10][2];
int weight[300][1 << 10][2];


ll f(int idx, int zero, int mask, int less, vector<int> &arr) {
    if (idx == (int) arr.size() && !zero && mask == 0 && less == 0) return 1;
    if (idx == (int) arr.size()) return 0;

    int x = arr[idx];

    ll &ans = dp[idx][zero][mask][less];
    if (ans != -1) return ans;

    ans = 0;

    // try using 0
    int nless = less & (0 >= x);
    int nmask = mask;
    if (!zero) nmask &= ~(1 << 0);
    ans += f(idx + 1, zero, nmask, nless, arr);

    
    for (int i = 1; i < x; i++) {
        nmask = mask & ~(1 << i);
        ans += f(idx + 1, 0, nmask, 0, arr);
    }

    // try using x
    if (x != 0) {
        nmask = mask & ~(1 << x);
        nless = less;
        ans += f(idx + 1, 0, nmask, nless, arr);
    }

    if (less == 0) {
        for (int i = x + 1; i < 10; i++) {
            nmask = mask & ~(1 << i);
            ans += f(idx + 1, 0, nmask, 0, arr);
        }
    }

    return ans;
}

ll solve(ll d) {
    if (d > 10) return 0;
    vector<int> st;
    for (int i = 0; i < (1 << 10); i++) {
        if (__builtin_popcount(i) == d) {
            st.push_back(i);
        }
    }

    memset(weight, 0, sizeof(weight));
    weight[0][0][0] = 1;
    for (int j = 0; j < (int) st.size(); j++) {
        for (int bitmask = 0; bitmask < (1 << 10); bitmask++) {
            int nmask = st[j] | bitmask;
            weight[j + 1][nmask][0] += weight[j][bitmask][1];
            weight[j + 1][nmask][1] += weight[j][bitmask][0];


            weight[j + 1][bitmask][0] += weight[j][bitmask][0];
            weight[j + 1][bitmask][1] += weight[j][bitmask][1];
        }
    }

    int n = st.size();
    ll ans = 0;


    vector<ll> cnt(1 << 10);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < (1 << 10); i++) {
        cnt[i] += f(0, 1, i, 1, upper);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < (1 << 10); i++) {
        cnt[i] -= f(0, 1, i, 1, lower);
    }

    for (int i = 0; i < (1 << 10); i++) {
        if (__builtin_popcount(i) < d) continue;
        ll w = weight[(int)st.size()][i][1] - weight[(int)st.size()][i][0];
        if (i == 0) w = 1;

        ll x = cnt[i];
        if (x < k) continue;

        ll res = 1;
        for (ll j = x - k + 1; j <= x; j++) {
            res *= (j % MOD);
            res %= MOD;
        }
        res *= inv[k];
        res %= MOD;

        ans += (w * res) % MOD;
        ans %= MOD;
    }
    return (ans + MOD) % MOD;
}

int power(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res *= a;
        a *= a;
        b /= 2;
        a %= MOD;
        res %= MOD;
    }
    return res;
}

int main() {
    int T; cin >> T;
    int fac = 1;
    for (int i = 1; i <= 10; i++) {
        fac *= i;
        inv[i] = power(fac, MOD - 2);
    }
    while(T--) {
        ll d; cin >> A >> B >> k >> d;

        upper.clear();
        lower.clear();
        
        for (char c: to_string(B + 1)) upper.push_back(c - '0');
        for (char c: to_string(A)) lower.push_back(c - '0');

        // first count sequences with >= d familiar digits
        // then count sequences with > d familiar digits
        ll ans = solve(d) - solve(d + 1);
        ans = ((ans % MOD) + MOD) % MOD;
        cout << ans << endl;
    }   
}