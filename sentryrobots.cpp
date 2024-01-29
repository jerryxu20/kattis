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

vs expand(vs &grid) {
    string r = string(sz(grid[0]), '.');
    vs ans;
    trav(row, grid) {
        ans.pb(r);
        rep(i, 0, sz(row)) {
            if (row[i] == '#') {
                ans.pb(r);
            }
            ans.back()[i] = row[i];
        }
    }
    return ans;
}

vs tranpose(vs &grid) {
    int n = sz(grid);
    int m = sz(grid[0]);

    vs ans(m, string(n, ' '));
    rep(i, 0, n) {
        rep(j, 0, m) {
            ans[j][i] = grid[i][j];
        }
    }
    return ans;
}

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

int solve(int tt) {
    int n, m;
    cin >> n >> m;
    vs grid(n, string(m, '.'));
    int p; cin >> p;

    while(p--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        grid[x][y] = '*';
    }

    int w; cin >> w;
    while(w--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        grid[x][y] = '#';
    }

    grid = expand(grid);
    grid = tranpose(grid);
    grid = expand(grid);
    // grid = tranpose(grid);

    int N = 0;
    int M = 0;

    vii row_id(n, vi(m)), col_id(n, vi(m));


    rep(i, 0, n) {
        rep(j, 0, m) {
            
        }
    }



    vi btoa(sz(grid[0]), -1);
    vii adj(sz(grid));

    rep(i, 0, sz(grid)) {
        rep(j, 0, sz(grid[0])) {
            if (grid[i][j] == '*') {
                adj[i].pb(j);
            }
        } 
    }

    cout << hopcroftKarp(adj, btoa) << nl;

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}