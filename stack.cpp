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

string s;
int solve(int tt) {
    getline(cin, s);
    int n = sz(s);

    // dp[i][j]: min cost to display s[i..j]
    vii dp(n, vi(n, 0));
    rep(l, 0, n) {
        rep(i, 0, n) {
            int j = i + l;
            if (j >= n) break;

            if (i == j) {
                // push char then pop
                dp[i][j] = 3;
                continue;
            }

            int ans = dp[i][j - 1] + 3;
            rep(k, i, j) {
                if (s[k] != s[j]) continue;

                // print this char
                ans = min(ans, dp[i][k] + dp[k + 1][j - 1] + 1);
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[0][n - 1] << endl;
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    getline(cin, s);
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}