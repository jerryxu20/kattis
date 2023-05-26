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
    int n, m, k;
    cin >> n >> m;
    vector<pair<vi, int>> prize(n);
    for (auto &[sticks, val]: prize) {
        cin >> k;
        sticks.resize(k);
        for (auto &s: sticks) cin >> s;
        cin >> val;
    }
    vi cnt(m);
    for (auto &c: cnt) cin >> c;
    int ans = 0;
    for (auto &[sticks, val] : prize) {
        int mn = INT_MAX;
        for (auto &s: sticks) { 
            mn = min(mn, cnt[s - 1]);
        }
        ans += mn * val;
    }
    cout << ans << endl;

    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}