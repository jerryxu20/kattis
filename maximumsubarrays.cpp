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
typedef vector<vl> vii;
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

int solve(int tt) {
    int n, k;
    cin >> n >> k;
    vi arr(n);
    trav(a, arr) cin >> a;
    vii dp(k + 1, vl(2, LLONG_MIN));
    dp[0][0] = 0;
    rep(i, 1, n + 1) {
        FORd(j, 0, k + 1) {
            if (j == 0) {
                dp[j][0] = 0;
                dp[j][1] = 0;
                continue;
            }
            // take this number
            if (dp[j][1] != LLONG_MIN) {
                dp[j][1] = dp[j][1] + arr[i - 1];
            }
            if (dp[j - 1][0] != LLONG_MIN) {
                dp[j][1] = max(dp[j][1], dp[j - 1][0] + arr[i - 1]);
            }

            // don't take this number
            dp[j][0] = max(dp[j][1], dp[j][0]);
        }
    }
    cout << dp.back()[0] << nl;

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