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

vpi delta = {{0, 1}, {1, 0}};

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(all(btoa), -1);
}

vi cover(vector<vi>& g, int n, int m) {
	vi match(m, -1);
	int res = dfsMatching(g, match);
	vector<bool> lfound(n, true), seen(m);
	for (int it : match) if (it != -1) lfound[it] = false;
	vi q, cover;
	rep(i,0,n) if (lfound[i]) q.push_back(i);
	while (!q.empty()) {
		int i = q.back(); q.pop_back();
		lfound[i] = 1;
		for (int e : g[i]) if (!seen[e] && match[e] != -1) {
			seen[e] = true;
			q.push_back(match[e]);
		}
	}
	rep(i,0,n) if (!lfound[i]) cover.push_back(i);
	rep(i,0,m) if (seen[i]) cover.push_back(n+i);
	assert(sz(cover) == res);
	return cover;
}

int n, m;

int id(int i, int j) {
    return i * m + j;
}

struct UF {
    vi rank, id, edge, group;
    UF(int n) {
        rank.resize(n);
        id.resize(n);
        edge.resize(n);
        group.resize(n);
        iota(all(id), 0);
    }

    int find(int a) {
        if (id[a] == a) return a;
        id[a] = find(id[a]);
        return id[a];
    }


    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[b] > rank[a]) swap(a, b);
        rank[a] += rank[b];
        id[b] = a;
        edge[a] |= edge[b];
        edge[b] = 0;
        return true;
    }
    
    void set(int a) {
        a = find(a);
        edge[a] = 1;
        return;
    }

    void set_group(int a, int g) {
        group[find(a)] = g;
    }
};


int solve(int tt) {
    cin >> n >> m;
    vs grid(n);
    trav(s, grid) cin >> s;

    UF uf(n * m);
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                uf.set(id(i, j));
            }
            uf.set_group(id(i, j), grid[i][j] == '1');
            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                if (grid[i][j] != grid[ii][jj]) continue;
                uf.join(id(i, j), id(ii, jj));
            }
        }
    }
    vii adj(n * m);
    
    rep(i, 0, n) {
        rep(j, 0, m) {
            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                int v = uf.find(id(ii, jj));
                int u = uf.find(id(i, j));
                if (u == v) continue;
                assert(grid[i][j] != grid[ii][jj]);
                if (uf.edge[v] == 1 || uf.edge[u] == 1) continue;
                
                // there is an edge
                if (uf.group[u] == 1) swap(u, v);
                adj[u].pb(v);
            }
        }
    }

    vi res = cover(adj, n * m, n * m);
    cout << sz(res) + count(all(uf.edge), 1) << endl;

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