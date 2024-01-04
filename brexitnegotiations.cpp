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

int n;
vi val;
void dfs(int node, vii &adj, vi &seen, vi &ans) {
    seen[node] = 1;
    trav(nxt, adj[node]) {
        if (seen[nxt]) continue;
        dfs(nxt, adj, seen, ans);
    }
    ans.pb(node);
    return;
}

vi topo(vii &adj) {
    vi ans, seen(n);
    rep(i, 0, n) {
        if (seen[i]) continue;
        dfs(i, adj, seen, ans);
    }
    return ans;
}

bool check(int x, vi &order, vii&adj, vii &tadj) {
    PQG<pi> pq;
    // adj[i]: what my dependencies are
    // tadj[i]: what depends on me
    vi dp(n, n);
    for (int node: order) {
        dp[node] = x - val[node];
        trav(nxt, tadj[node]) {
            dp[node] = min(dp[node], dp[nxt] - 1);
        }
    }

    vi deg(n);
    rep(i, 0, n) {
        deg[i] = sz(adj[i]);
        if (deg[i] == 0) pq.push({dp[i], i}); 
    }

    int mx = 0;
    int done = 0;
    bool bad = false;
    while(sz(pq)) {
        auto [before, node] = pq.top();
        if (done > before) bad = true;
        pq.pop();
        mx = max(mx, val[node] + done);
        done++;
        trav(nxt, tadj[node]) {
            deg[nxt]--;
            if (deg[nxt] == 0) {
                pq.push({dp[nxt], nxt});
            }
        }
    }
    if (bad) assert(mx > x);
    return mx <= x;
}

int solve(int tt) {
    // the min time a meeting can take is its time + the number of dependencies
    cin >> n;

    vii adj(n), tadj(n);
    val.resize(n);
    rep(i, 0, n) {
        cin >> val[i];
        int m; cin >> m;
        while(m--) {
            int nxt; cin >> nxt;
            nxt--;
            adj[i].pb(nxt);
            tadj[nxt].pb(i);
        }
    }

    vi order = topo(tadj);
    int low = 0;
    int high = 1e6 + n;
    int ans = INT_MAX;
    while(low <= high) {
        int mid = (low + high)/2;
        // cout << mid << endl;
        if (check(mid, order, adj, tadj)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    // assert(ans != INT_MAX);
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