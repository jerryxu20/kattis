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
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vii;
typedef vector<vii> viii;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define rep(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

/*
.... 0 (pad)
#### 1
..## 2
#.#. 3
...# 4
*/

int n, m;

bool validsupport(int top, int bot) {
    for (int i = 0; i < m; i++) {
        // if the top needs support and the bottom has support
        if (top & (1 << i) && bot & (1 << i)) {
            // if previous square needs support then support it
            // otherwise support next square
            if (i > 0 && top & (1 << (i - 1))) {
                top &= ~((1 << i) + (1 << (i - 1)));
            } else {
                top &= ~((1 << i) + (1 << (i + 1)));
            }
        }
    }
    return __builtin_popcount(top) == 0;
}

bool goodcover(int top, int bot, int cover) {
    // check if cover is valid
    int ncover = cover;
    for (int i = 0; i < m; i++) {
        if (ncover & (1 << i) && !(ncover & (1 << (i + 1)))) return false;
        if (ncover & (1 << i)) ncover &= ~(1 << (i + 1));
    }
    // check if the top row and bottom row are subsets of cover
    return (top | bot | cover) == cover;
}

int solve(int tt) {
    cin >> n >> m;
    string s;
    vi grid(n + 1);
    FOR(i, 1, n + 1) {
        cin >> s;
        int row = 0;
        for (int i = 0; i < m; i++) {
            if (s[i]== '#') row += (1 << i);
        }
        grid[i] = row;
    }

    int mx = 1 << m;
    vii dp(n/2 + 1, vi(mx, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n/2; i++) {
        int toprow = i*2 - 1;
        int botrow = i*2;
        for (int j = 0; j < mx; j++) {
            if (dp[i - 1][j] == INT_MAX) continue;
            for (int k = 0; k < mx; k++) {
                if (!validsupport(j, k) || !goodcover(grid[toprow], grid[botrow], k)) continue;
                int boxes = __builtin_popcount(k)/2;
                dp[i][k] = min(dp[i][k], boxes + dp[i - 1][j]);
            }
        }
    }

    cout << *min_element(all(dp.back())) << nl;
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
