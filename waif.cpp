#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


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


int main() {
    int n, m, p; cin >> n >> m >> p;

    // each child is a node
    // each toy is a node
    // each category is a node

    Dinic flow(n + m + p + 2);

    int s = n + m + p;
    int t = n + m + p + 1;

    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        int toy;
        while(k--) {
            cin >> toy; toy--;
            flow.addEdge(i, n + toy, 1);
        }
        flow.addEdge(s, i, 1);
    }

    vector<int> used(m);
    for (int i = 0; i < p; i++) {
        int k; cin >> k;
        int toy;
        while(k--) {
            cin >> toy; toy--;
            assert(used[toy] == 0);
            used[toy] = 1;
            flow.addEdge(n + toy, n + m + i, 1);
        }
        int cap; cin >> cap;
        flow.addEdge(n + m + i, t, cap);
    }

    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            flow.addEdge(n + i, t, 1);
        }
    }

    cout << flow.calc(s, t) << endl;


}