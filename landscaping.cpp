/*
BEGIN-HEADER

Name: Jerry Xu

Student-ID: 1704990

List any resources you used below (eg. urls, name of the algorithm from our code archive).
Remember, you are permitted to get help with general concepts about algorithms
and problem solving, but you are not permitted to hunt down solutions to
these particular problems!

<List Resources Here>

List any classmate you discussed the problem with. Remember, you can only
have high-level verbal discussions. No code should be shared, developed,
or even looked at in these chats. No formulas or pseudocode should be
written or shared in these chats.

<List Classmates Here>

By submitting this code, you are agreeing that you have solved in accordance
with the collaboration policy in CMPUT 303/403.

END-HEADER
*/
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

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int n, m, a, b;

int id(int i, int j) {
    return i * m + j;
}

vpi delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int solve(int tt) {
    cin >> n >> m;
    cin >> a >> b;
    vs grid(n);
    trav(s, grid) cin >> s;

    int sink = n * m;
    int source = n * m + 1;


    Dinic flow(n * m + 2);

    rep(i, 0, n) {
        rep(j, 0, m) {
            trav(d, delta) {
                int ii = i + d.first;
                int jj = j + d.second;
                if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                int cost = a;
                // if (grid[i][j] == grid[ii][jj]) cost = 0;
                flow.addEdge(id(i, j), id(ii, jj), cost);
            }
            if (grid[i][j] == '#') {
                flow.addEdge(source, id(i, j), b);
            } else {
                flow.addEdge(id(i, j), sink, b);
            }
        }
    }

    cout << flow.calc(source, sink) << endl;

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