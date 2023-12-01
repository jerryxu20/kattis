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
int n, s;
vii DP[2];
vii adj;
void dfs(int node, int par) {
    trav(nxt, adj[node]) {
        if (nxt == par) continue;
        dfs(nxt, node);


        // we are including this node
        vi &dp = DP[1][node];
        vi &dp2 = DP[0][node];
        vi &choice = DP[0][nxt];
        vi &choice2 = DP[1][nxt];
        vi ans(s + 1), ans2(s + 1);
        rep(i, 0, s + 1) {
            // cost is i, 
            FORd(j, 0, s + 1) {
                if (j - i < 0) break;
                ans[j] = max({ans[j], dp[j], dp[j - i] + choice[i]});
            } 
        }

        rep(i, 0, s + 1) {
            FORd(j, 0, s + 1) {
                if (j - i < 0) break;
                ans2[j] = max({ans2[j], dp2[j], dp2[j - i] + max(choice[i], choice2[i])});
            }
        }
        rep(i, 0, s + 1) {
            dp[i] = ans[i];
            dp2[i] = ans2[i];
        }

    }
}

int solve(int tt) {

    cin >> n >> s;
    DP[0].resize(n, vi(s + 1));
    DP[1].resize(n, vi(s + 1));
    adj.resize(n);

    // cost, power
    int a, b;
    rep(i, 0, n) {
        cin >> a >> b;
        vi &dp = DP[1][i];
        FORd(i, 0, s + 1) {
            if (i - a < 0) break;
            dp[i] = dp[i - a] + b;
        }
    }
    rep(_, 1, n) {
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);

    cout << max(DP[0][0].back(), DP[1][0].back()) << nl;
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