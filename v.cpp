#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int allowed[10];
const int MX = 800;
ll x;

ll dp[12][MX][2][2];

ll f(int idx, int mod, int less, int zero, vector<int> &upper) {
    if (idx == (int)upper.size() && mod == 0 && less == 0) return 1;
    if (idx == (int)upper.size()) return 0;

    ll &ans = dp[idx][mod][less][zero];
    if (ans != -1) return ans;

    ans = 0; 
    // try using zero
    if (zero) {
        assert(idx != 0 || upper[idx] != 0);
        ans += f(idx + 1, (mod * 10) % x, 0, 1, upper);
    } else if (allowed[0]) {
        int nless = less & (0 == upper[idx]);
        ans += f(idx + 1, (mod * 10) % x, nless, 0, upper);
    }


    for (int i = 1; i < upper[idx]; i++) if (allowed[i]) {
        int nmod = (mod * 10 + i) % x;
        ans += f(idx + 1, nmod, 0, 0, upper);
    }

    if (less == 0) {
        for (int i = upper[idx] + 1; i < 10; i++) if (allowed[i]) {
            int nmod = (mod * 10 + i) % x;
            ans += f(idx + 1, nmod, 0, 0, upper);
        }
    }

    if (upper[idx] != 0 && allowed[upper[idx]]) {
        int nmod = (mod * 10 + upper[idx]) % x;
        ans += f(idx + 1, nmod, less, 0, upper);
    }

    return ans;
}


int main() {
    ll a, b; cin >> x >> a >> b;

    string s; cin >> s;
    for (char &c: s) {
        allowed[c - '0'] = 1;
    }    

    if (x > MX) {
        int ans = 0;
        for (ll i = x; i <= b; i += x) if (i >= a) {
            int inc = 1;
            for (char &c: to_string(i)) {
                if (!allowed[c - '0']) inc = 0;
            }
            ans += inc;
        }
        cout << ans << endl;
        return 0;
    }

    vector<int> A, B;
    for (auto &c: to_string(a)) A.push_back(c - '0');
    for (auto &c: to_string(b + 1)) B.push_back(c - '0');

    memset(dp, -1, sizeof(dp));
    ll ans = f(0, 0, 1, 1, B);
    memset(dp, -1, sizeof(dp));
    ans -= f(0, 0, 1, 1, A);
    
    cout << ans << endl;
}