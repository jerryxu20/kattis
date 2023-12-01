#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;
typedef tuple<int,int,int> ti;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vii;
typedef vector<vii> viii;

template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for (int i=a; i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(x,A) for (auto& x : A)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

vpi delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int solve(int tt) {
    int n, f;
    cin >> n >> f;

    vii grid(n, vi(n));
    trav(row, grid) {
        trav(cell, row) cin >> cell;
    }

    // start at the large values, 
    vii dp(n, vector<int>(n, -1));
    vpi nodes;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                dp[i][j] = grid[i][j];
            }
            nodes.pb(mp(i, j));
        }
    }

    sort(all(nodes), [&](auto &a, auto &b) {
        return grid[a.first][a.second] > grid[b.first][b.second];
    });

    int ans = 0;
    rep(k, 0, f) {
        // dp[i][j]: max we can earn ending at i, j
        for (auto &[i, j]: nodes) {
            trav(d, delta) {
                int ii = i + d.first;
                int jj = j + d.second;

                if (ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
                if (grid[ii][jj] >= grid[i][j]) continue;
                if (dp[ii][jj] == -1) continue;
                dp[i][j] = max(dp[i][j], dp[ii][jj] + grid[i][j]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << nl;

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}