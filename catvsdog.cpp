#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef long long ll;
typedef vector<int> vi;

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

struct Vote {
    int cat, dog;
};

void solve () {
    int c, d, v; cin >> c >> d >> v;

    vector<Vote> catlover, doglover;
    for (int i = 0; i < v; i++) {
        string a, b; cin >> a >> b;
        if (a[0] == 'C') {
            int cat = stoi(a.substr(1));
            int dog = stoi(b.substr(1));
            catlover.push_back(Vote{cat, dog});
        } else {
            int dog = stoi(a.substr(1));
            int cat = stoi(b.substr(1));
            doglover.push_back(Vote{cat, dog});
        }
    }

    vector<vector<int>> adj(v);
    for (int i = 0; i < catlover.size(); i++) {
        for (int j = 0; j < doglover.size(); j++) {
            if (catlover[i].cat == doglover[j].cat || catlover[i].dog == doglover[j].dog) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> btoa(v, -1);
    int ans = hopcroftKarp(adj, btoa);
    cout << v - ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}