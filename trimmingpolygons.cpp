#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200;

int n;
pair<ll, ll> pts[MAXN]; 
ll val[MAXN];

ll dp[MAXN + 1][MAXN + 1];

ll cross(pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.first * b.second - b.first * a.second;
}

ll f(int l, int r, int poly) {

    if (l == n - 1) {
        // connect to end
        if (poly != n) {
            return cross(pts[n - 1], pts[poly]);
        } else {
            return val[n - 1];
        }
    }

    ll &ans = dp[l][poly];
    if (ans != -1) return ans;
    ans = 0;
    
    if (poly != n) {
        // l is part of polygon
        // connect i to l
        ll cur = 0;
        for (int i = (l + 1) %n; i != n - 1; i = (i + 1) % n) {
            // edge l -> i
            ans = max(ans, cross(pts[l], pts[i]) + cur + f(i, n - 1, poly));
            cur += val[i];
        }

        // edge l -> n - 1
        ans = max(ans, cross(pts[l], pts[n - 1]) + cur + f(n - 1, n - 1, poly));
        cur += val[n - 1];
        
        // finish polygon at l
        ans = max(ans, cross(pts[l], pts[poly]) + cur);
        return ans;
    } 

    // skip l
    ans = max(ans, f((l + 1) % n, n - 1, poly) + val[l]);

    // start polygon at l
    ans = max(ans, f(l, n - 1, l));
    return ans;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second >> val[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << f(0, n - 1, n) << endl;
}