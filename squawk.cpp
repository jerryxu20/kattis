#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
// typedef pair<int, int> pii;
typedef pair<ll, ll> pii;
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
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vpii edges(m);
    for (auto &[a, b]: edges) {
        cin >> a >> b;
    }
    vector<vector<ll>> squawks(t + 1, vector<ll>(n));
    squawks[0][s] = 1;
    for (int i = 1; i <= t; i++) {
        for (auto &[a, b]: edges) {
            squawks[i][a] += squawks[i - 1][b];
            squawks[i][b] += squawks[i - 1][a];
        }
    }
    ll ans = 0;
    for (auto &a: squawks.back()) {
        ans += a;
    }
    cout << ans << endl;
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