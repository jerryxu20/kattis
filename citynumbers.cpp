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

void dfs(int node, int par, vi &color, vii &adj) {
    for (int nxt: adj[node]) {
        if (nxt == par) continue;
        color[nxt] = color[node] ^ 1;
        dfs(nxt, node, color, adj);
    }
    return;
}

int n, k;

map<pi, int> dp;

int dfs(int node, int par, int bad, vii &adj) {
    pi state = {node, bad};
    if (dp.count(state)) return dp[state];
    int ans = INT_MAX;
    for (int c = 1; c <= min(3, k); c++) {
        if (c == bad) continue;
        int cand = c;
        for (int nxt: adj[node]) {
            if (nxt != par) {
                cand += dfs(nxt, node, c, adj);
            }
        }
        ans = min(ans, cand);
    }
    dp[state] = ans;
    return ans;
}

int solve(int tt) {
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (k == 1) {
        cout << -1 << endl;
        return 0;
    }

    vii adj(n);
    rep(i, 1, n) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int ans = dfs(n - 1, -1, -1, adj);
    assert(ans != INT_MAX);

    cout << ans << endl;
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