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
const int LOG = 20;
const int MAXN = 5e4;

int UP[MAXN][LOG];
vi adj[MAXN];
int height[MAXN];

struct UF {
    vi id, rank;
    UF(int n) {
        id.resize(n);
        iota(all(id), 0);
        rank.resize(n, 1);
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
        return true;
    }
};

void dfs(int node, int par, int level) {
    UP[node][0] = par;
    height[node] = level;
    for (int &nxt: adj[node]) if (nxt != par) {
        dfs(nxt, node, level + 1);
    }
    return;
}

int jump(int node, int x) {
    rep(i, 0, LOG) if (x & (1 << i)) {
        node = UP[node][i];
    }
    return node;
}

int lca(int a, int b) {
    // b is below a
    if (height[a] > height[b]) swap(a, b);

    b = jump(b, height[b] - height[a]);
    if (a == b) {
        // cout << "lca " << a <<  " " << b << " " << a << endl;
        return a;
    }

    for (int i = LOG - 1; i >= 0; i--) {
        int aa = UP[a][i];
        int bb = UP[b][i];

        if (aa != bb) {
            a = aa;
            b = bb;
        }
    }
    return UP[a][0];
}

bool interline(const pi &A, const pi &B) {
    int x = lca(A.first, B.first);

    if (lca(x, A.second) != A.second) return false;
    if (lca(x, B.second) != B.second) return false;

    return true;

}

bool inter(const pi &A, const pi &B) {
    int x = lca(A.first, A.second);
    int y = lca(B.first, B.second);

    bool ans = false;
    if (interline({A.first, x}, {B.first, y})) ans = true;
    if (interline({A.first, x}, {B.second, y})) ans = true;
    if (interline({A.second, x}, {B.first, y})) ans = true;
    if (interline({A.second, x}, {B.second, y})) ans = true;
    return ans;
}


bool valid(const vpi &path) {
    int n = sz(path);
    rep(i, 0, n) {
        rep(j, 0, i) {
            if (inter(path[i], path[j])) return false;
        }
    }
    return true;
}

int solve(int tt) {
    int n, q; cin >> n >> q;

    UF uf(n);
    vpi extra;

    rep(i, 0, n + 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (uf.join(a, b)) {
            adj[a].pb(b);
            adj[b].pb(a);
        } else {
            extra.pb({a, b});
        }
    }

    dfs(0, -1, 0);

    rep(i, 1, LOG) {
        rep(node, 0, n) {
            int x = UP[node][i - 1];
            if (x == -1) UP[node][i] = -1;
            else UP[node][i] = UP[x][i - 1];
        }
    }

    while(q--) {
        int u, v; cin >> u >> v;
        u--; v--;

        auto &[a, b] = extra[0];
        auto &[c, d] = extra[1];

        int ans = 1;
        if (valid({{u, a}, {b, v}})) ans++;
        if (valid({{u, b}, {a, v}})) ans++;
        if (valid({{u, c}, {d, v}})) ans++;
        if (valid({{u, d}, {c, v}})) ans++;

        if (valid({{u, a}, {b, c}, {d, v}})) ans++;
        if (valid({{u, a}, {b, d}, {c, v}})) ans++;
        if (valid({{u, b}, {a, c}, {d, v}})) ans++;
        if (valid({{u, b}, {a, d}, {c, v}})) ans++;

        if (valid({{u, c}, {d, a}, {b, v}})) ans++;
        if (valid({{u, c}, {d, b}, {a, v}})) ans++;
        if (valid({{u, d}, {c, a}, {b, v}})) ans++;
        if (valid({{u, d}, {c, b}, {a, v}})) ans++;

        cout << ans << nl;
    }

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