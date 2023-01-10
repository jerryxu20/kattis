#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

double choose(int n, int k) {
    double ans = tgamma(n + 1) / ((tgamma(k + 1)) * tgamma(n - k + 1));
    // cout << n << " choose " << k << " " << ans << endl;
    return ans;
}


int main() {
    int test;
    cin >> test;
    while (test--) {
        int r, s, x, y, w;
        cin >> r >> s >> x >> y >> w;
        // r is the target x/y is the freq s is the side, w is the multiplier
        int good_rolls = s - r  + 1;
        double good_prob = good_rolls / double(s);
        double bad_prob = 1.0 - good_prob;
        double prob = 0;
        for (int k = x; k <= y; k++) {
            prob += choose(y, k) * pow(good_prob, k) * pow(bad_prob, y - k);
        }
        double expected = prob * w;
        if (expected > 1) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}