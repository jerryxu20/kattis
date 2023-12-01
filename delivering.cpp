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


vl dijk(int s, vector<vpl> &adj) {
    vl ans(sz(adj), LLONG_MAX);
    ans[s] = 0;

    PQG<pl> pq;
    pq.push({0, s});

    while(sz(pq)) {
        auto [dis, node] = pq.top();
        pq.pop();
        if (dis != ans[node]) continue;
        for (auto &[nxt, cost]: adj[node]) {
            if (dis + cost >= ans[nxt]) continue;
            ans[nxt] = dis + cost;
            pq.push({dis + cost, nxt});
        }
    }
    return ans;
}

int solve(int tt) {
    int n, m, c; cin >> n >> m >> c;

    vector<vpl> adj(n);
    vi nodes(c);
    trav(node, nodes) cin >> node;
    nodes.pb(0);
    
    ll a, b, cost;
    while(m--) {
        cin >> a >> b >> cost;
        adj[a].pb({b, cost});
    }
    vii m_adj(c + 1);
    vl dis = dijk(0, adj);
    sort(all(nodes), [&] (auto &a, auto &b){
        return dis[a] < dis[b];
    });

    rep(i, 0, c + 1) {
        int s = nodes[i];
        vl dis2 = dijk(s,adj);
        rep(j, i + 1, c + 1) {
            int t = nodes[j];
            if (dis[t] == dis[s] + dis2[t]) {
                m_adj[i].pb(j);
            }
        }
    }

    vi matching(c + 1, -1);
    cout << c + 1 - hopcroftKarp(m_adj, matching) << nl;
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