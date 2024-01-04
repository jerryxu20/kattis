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

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

void dfs(int node, vii &adj, vi &seen, vi &order) {
    seen[node] = 1;
    trav(nxt, adj[node]) {
        if (seen[nxt]) continue;
        dfs(nxt, adj, seen, order);
    }
    order.pb(node);
    return;
}


int solve(int tt) {
    int n, m;
    cin >> n >> m;

    // run flow to find matching, then put unsaturated edges int adj, then scc then dp

    vii match(n);
    int a, b;
    rep(_, 0, m) {
        cin >> a >> b;
        a--; b--;
        match[a].pb(b);
    }

    vi btoa(n, -1);
    int planes = n - hopcroftKarp(match, btoa) - 1;
    cout << planes << nl;
    
    if (planes == 0) return 0;

    // Build graphs using augmenting edges
    vi indeg(2 * n), outdeg(2 * n);
    vii adj(2 * n), t_adj(2 * n);

    rep(i, 0, n) {
        trav(j, match[i]) {
            if (i == btoa[j]) continue;
            adj[i].pb(j + n);
            t_adj[j + n].pb(i);

            outdeg[i]++;
            indeg[j + n]++;
        }
    }
    
    rep(i, 0, n) {
        if (btoa[i] == -1) continue;
        adj[i + n].pb(btoa[i]);
        t_adj[btoa[i]].pb(i + n);

        outdeg[i + n]++;
        indeg[btoa[i]]++;
    }

    // SCC
    vi order;
    vi seen(2 * n);

    rep(i, 0, 2*n) {
        if (seen[i] == 0) dfs(i, adj, seen, order);
    }

    reverse(all(order));
    seen.assign(2 * n, 0);
    
    vi id(2 * n), comp;
    int N = 0;

    trav(node, order) {
        if (seen[node]) continue;
        dfs(node, t_adj, seen, comp);

        trav(c, comp) {
            id[c] = N;
        }
        N++;
        comp.clear();
    }

    // dp1[i]: is node i reachable from a node on the left side with 0 indegree
    // dp2[i]: can node i reach a node on the right side with 0 outdegree
    vi dp1(N), dp2(N);
    vii radj(N);

    rep(i, 0, 2*n) {
        if (i < n && indeg[i] == 0) {
            dp1[id[i]] = 1;
        }
        if (i >= n && outdeg[i] == 0) {
            dp2[id[i]] = 1;
        }
        trav(nxt, adj[i]) {
            if (id[i] == id[nxt]) continue;
            radj[id[i]].pb(id[nxt]);
        }
    }
    
    rep(i, 0, N) {
        if (dp1[i] == 0) continue;
        trav(nxt, radj[i]) {
            dp1[nxt] = 2;
        }
    }

    FORd(i, 0, N) {
        trav(nxt, radj[i]) {
            if (dp2[nxt]) dp2[i]++;
        }
    }

    rep(i, 0, n) {
        if (dp1[id[i]] || dp2[id[i + n]] ) {
            cout << i + 1 << " ";
        }
    }
    cout << nl;

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