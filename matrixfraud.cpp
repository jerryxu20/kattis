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

vii transpose(vii &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vii ans(m, vi(n));

    rep(i, 0, n) {
        rep(j, 0, m) {
            ans[j][i] = grid[i][j];
        }
    }
    return ans;
}


int solve(int tt) {
    int n, m;
    cin >> n >> m;

    vii grid(n, vi(m));

    trav(row, grid) {
        trav(x, row) {
            char c; cin >> c;
            x = c - '0';
        }
    }

    if (n < m) {
        grid = transpose(grid);
        swap(n, m);
    }

    vii psum(n, vi(m + 1));
    rep(i, 0, n) {
        rep(j, 0, m) {
            psum[i][j + 1] = psum[i][j] + grid[i][j];
        }
    }

    vector<vii> dp(n, vii(m, vi(m, 1e9)));
    vii mn(m, vi(m, 1e9));
    rep(j, 0, 1) {
        rep(k, j, m) {
            int total = psum[0].back();
            int good = psum[0][k + 1] - psum[0][j];
            
            // 1s not in the range + 0s in the range
            dp[0][j][k] = (total - good) + (k - j + 1 - good);
        }
    }

    rep(j, 0, m) {
        rep(k, 0, m) {
            mn[k][j] = dp[0][j][k];
            if (j > 0) {
                mn[k][j] = min(mn[k][j], mn[k][j - 1]);
            }
        }
    }

    rep(i, 1, n) {
        rep(j, 0, m) {
            rep(k, j, m) {
                if (k > j) {
                    // [j, k - 1] extending to [j, k]
                    int diff;
                    if (grid[i][k] == 0) diff = 1;
                    else diff = -1;
                    
                    dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1] + diff);
                }

                int total = psum[i].back();
                int good = psum[i][k + 1] - psum[i][j];
                int prev = mn[k][j];
                if (j == k && k > 0) {
                    prev = min(prev, mn[k - 1][j - 1]); 
                }
                if (prev != 1e9) {
                    int cost = (total - good) + (k - j + 1 - good) + prev;
                    dp[i][j][k] = min(dp[i][j][k], cost);
                }
            }
        }

        rep(j, 0, m) {
            rep(k, 0, m) {
                mn[k][j] = dp[i][j][k];
                if (j > 0) {
                    mn[k][j] = min(mn[k][j], mn[k][j - 1]);
                }
            }
        }
    }

    int ans = 1e9;
    rep(j, 0, m) {
        ans = min(ans, dp[n - 1][j][m - 1]);
    }

    cout << ans << nl;
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