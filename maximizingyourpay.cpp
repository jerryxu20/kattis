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

int n, m;

int dfs(int s, int t, int avail, vector<vii> &dp, vii &adj) {
    // done
    if (s == t && (avail & (1 << s)) == 0) return 0;
    
    // can loop back to start, which is bad
    if (s != t && (avail & (1 << s))) return INT_MIN;

    // cannot reach end
    if (s != t && (avail & (1 << t)) == 0) return INT_MIN;
    
    if (dp[s][t][avail] != -1) return dp[s][t][avail];
    
    int ans = INT_MIN;
    trav(nxt, adj[s]) {
        if ((avail & (1 << nxt)) == 0) continue;
        int cand = dfs(nxt, t, avail & ~(1 << nxt), dp, adj);
        if (cand == INT_MIN) continue;
        ans = max(ans, 1 + cand);
    }
    dp[s][t][avail] = ans;
    // cout << s << " " << t << " " << bitset<k8>(avail).to_string() <<  " " << ans << nl;
    return ans;
}

int solve(int tt) {
    cin >> n;
    if (n == 0) return 1;

    cin >> m;

    vii adj(n);

    int a, b;
    rep(i, 0, m) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    if (sz(adj[0]) == 0) {
        cout << 1 << nl;
        return 0;
    }
    // start, end, avail
    vector<vii> dp(n, vii(n, vi(1 << n, -1)));
    int ans = dfs(0, 0, (1 << n) - 1, dp, adj); 
    cout << ans << nl;
    
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}