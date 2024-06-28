#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4;
ll cnt[MAXN];
int weight[] = {1, 5, 10, 25};

ll solve(ll n, int idx) {
    assert(n >= 0);

    if (n == 0) return 0;
    if (idx >= 4) return -1e9;

    ll ans = -1e9;
    if (idx == 0) {
        ll mx = min(n/5, cnt[idx]/5);
        
        for (ll i = max(0LL, mx - 4); i <= mx; i++) {
            ans = max(ans, i * 5 + solve(n - i * 5, idx + 1));
        }

        return ans;
    }
    
    ll mx = min(n/weight[idx], cnt[idx]);
    for (ll i = max(0LL, mx - 4); i <= mx; i++) {
        ans = max(ans, i + solve(n - i * weight[idx], idx + 1));
    }

    return ans;
}


int main() {
    ll p; cin >> p;

    for (int i = 0; i < 4; i++) cin >> cnt[i];

    int x = p % 5;
    if (cnt[0] < x) {
        cout << "Impossible\n";
        return 0;
    }

    cnt[0] -= x;
    ll ans = x + solve(p - x, 0);

    if (ans < 0) {
        cout << "Impossible\n";
    } else {
        cout << ans << endl;
    }
}