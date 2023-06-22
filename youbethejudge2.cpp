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


vii vert = {{1, 0}, {-1, 0}};
vii hort = {{0, 1}, {0, -1}};


int solve(int tt) {
    int n;
    cin >> n;
    vii grid(1 << n, vi(1 << n));
    trav(row, grid) {
        trav(cell, row) {
            cin >> cell;
        }
    }
    set<int> used;
    int zero = 0;
    rep(i, 0, 1 << n) {
        rep(j, 0, 1 << n) {
            if (used.count(grid[i][j])) {
                cout << 0 << nl;
                return 0;
            }
            if (grid[i][j] == -1) continue;
            if (grid[i][j] == 0) {
                grid[i][j] = -1;
                zero++;
                continue;
            }

            vpi updown;
            vpi leftright;
            int ii, jj;
            trav(d, vert) {
                ii = i + d[0];
                jj = j + d[1];
                if (ii < 0 || jj < 0 || ii >= (1 << n) || jj >= (1 << n)) continue;
                if (grid[ii][jj] != grid[i][j]) continue;
                updown.pb(mp(ii, jj));
            }
            trav(d, hort) {
                ii = i + d[0];
                jj = j + d[1];
                if (ii < 0 || jj < 0 || ii >= (1 << n) || jj >= (1 << n)) continue;
                if (grid[ii][jj] != grid[i][j]) continue;
                leftright.pb(mp(ii, jj));
            }

            if (sz(updown) == 2 || sz(leftright) == 2) {
                cout << 0 << nl;
                return 0;
            }

            if (sz(updown) == 1 && sz(leftright) == 1) {
                used.insert(grid[i][j]);
                grid[i][j] = -1;
                grid[updown[0].first][updown[0].second] = -1;
                grid[leftright[0].first][leftright[0].second] = -1;
            }
        }
    }

    trav(row, grid) {
        if (count(all(row), -1) != (1 << n)) {
            cout << 0 << nl;
            return 0;
        }
    }
    if (zero != 1) {
        cout << 0 << nl;
        return 0;
    }
    cout << 1 << nl;

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