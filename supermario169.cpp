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
double DP[1 << 13][13][13];

double dis(ti a, ti b) {
    ll ans = 0;
    auto [x1, y1, z1] = a;
    auto [x2, y2, z2] = b;

    ll dx = x1 - x2;
    ll dy = y1 - y2;
    ll dz = z1 - z2;

    ans += dx * dx + dy * dy + dz * dz;
    return sqrt(ans);
}

vector<double> helper(ti s, vector<ti> &coords) {

    // ans[i]: cost to collect all coins ending at i

    int n = sz(coords);
    vector<vector<double>> dp(1 << n, vector<double>(n, 1e9));
    // dp[sub][i]: cost to take care of the subset given that the previous one was i

    int mall = (1 << n) - 1;
    rep(i, 0, n) {
        dp[mall & ~(1 << i)][i] = dis(s, coords[i]);
    }

    for (int mask = (1 << n) - 2; mask >= 0; mask--) {
        rep(i, 0, n) {
            if (mask & (1 << i)) continue;
            rep(j, 0, n) if (mask & (1 << j)) {
                int nmask = mask & ~(1 << j);
                // by the time we get to nmask, j should not be set. 
                dp[nmask][j] = min(dp[nmask][j], dp[mask][i] + dis(coords[i], coords[j]));
            }
        }
    }
    vector<double> ans = dp[0];
    return ans;
}


int solve(int tt) {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<vector<double>> swit;
    vector<vector<ti>> pos;
    vector<ti> loc;
    int k, xx, yy, zz;
    rep(_, 0, n) {
        cin >> k >> xx >> yy >> zz;
        vector<ti> coords(k);
        for (auto &[a, b, c]: coords) cin >> a >> b >> c;

        swit.pb(helper({xx, yy, zz}, coords));
        pos.pb(coords);
        loc.pb({xx, yy, zz});
    }

    rep(i, 0, 1 << 13) {
        rep(j, 0, 13) {
            rep(k, 0, 13) {
                DP[i][j][k] = 1e9;
            }
        }
    }

    int mall = (1 << n) - 1;

    rep(i, 0, n) {
        int nmask = mall & ~(1 << i);
        rep(j, 0, sz(swit[i])) {
            DP[nmask][i][j] = swit[i][j] + dis({x, y, z}, loc[i]);            
        }
    }


    double ans = 1e9;
    for (int mask = (1 << n) - 2; mask >= 0; mask--) {
        rep(i, 0, n) {
            if (mask & (1 << i)) continue;
            rep(j, 0, sz(swit[i])) {
                if (mask == 0) ans = min(ans, DP[mask][i][j]);

                rep(ii, 0, n) if (mask & (1 << ii)) {
                    rep(jj, 0, sz(swit[ii])) {
                        int nmask = mask & ~(1 << ii);
                        DP[nmask][ii][jj] = min(DP[nmask][ii][jj], 
                            DP[mask][i][j] + dis(pos[i][j], loc[ii]) + swit[ii][jj]);
                    }
                }
            }
        }
    }

    cout << setprecision(15) << fixed << ans << nl;


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