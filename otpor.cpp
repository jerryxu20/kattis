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
string s;
vector<double> res;
int n;


pair<double, int> dfs(int idx) {
    vector<double> vals;
    bool op = true;
    int i;
    for (i = idx; i < sz(s); i++) {
        if (s[i] == 'R' || s[i] == '-') continue;
        if (s[i] == '(') {
            auto [r, j] = dfs(i + 1);
            vals.pb(r);
            i = j;
            continue;
        }
        if (s[i] == ')') break;
        if (s[i] == '|') {
            op = false;
            continue;
        }
        vals.pb(res[s[i] - '0']);
    }
    if (sz(vals) == 0) {
        while(true);
    }
    if (op) return mp(accumulate(all(vals), 0.0), i);
    for (auto &v: vals) v = 1/v;
    return mp(1/accumulate(all(vals), 0.0), i);
}




int solve(int tt) {
    cin >> n;
    res.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> res[i];

    cin >> s;
    cout << fixed << setprecision(10) << dfs(0).first << endl;

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    t++;
    return 0;
}