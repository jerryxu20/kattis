#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int tcase) {
    int n, mn, mx;
    cin >> n >> mn >> mx;
    vi plat(n);
    for (auto &p: plat) cin >> p;
    sort(all(plat));
    vi ans(n, mn);
    for (int i = 0; i < n; i++) {
        int cand = mx;
        if (i > 0) cand = min(cand, 2 * (plat[i] - plat[i - 1]) - ans[i - 1]);
        if (i + 1 < n) cand = min(cand, 2 * (plat[i + 1] - plat[i]) - ans[i + 1]);
        if (cand < mn) {
            cout << - 1 << endl;
            return 0;
        }
        ans[i] = cand;
    }
    int sm = 0;
    for (auto &a: ans) sm += a;
    cout << sm << endl;

    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}