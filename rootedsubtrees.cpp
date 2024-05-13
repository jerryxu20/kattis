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
const int MAXN = 2e5;
const int LOG = 20;

int parent[MAXN];
int up[MAXN][LOG];
int level[MAXN];
vector<int> adj[MAXN];
int n;

void dfs(int node, int par) {
    parent[node] = par;

    for (int &nxt: adj[node]) if (nxt != par) {
        level[nxt] = level[node] + 1; 
        dfs(nxt, node);
    }
    return;
}

int jump(int node, int x) {
    rep(i, 0, LOG) if (x & (1 << i)) {
        node = up[node][i];
    }
    return node;
}

int lca(int a, int b) {
    if (level[a] > level[b]) swap(a, b);
    b = jump(b, level[b] - level[a]);

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; i--) {
        int aa = up[a][i];
        int bb = up[b][i];
        if (aa == bb) continue;
        a = aa;
        b = bb;
    }
    return up[a][0];
}

int jumppath(int a, int b, int lca, int len) {
    int A = level[a] - level[lca];
    int B = level[b] - level[lca];

    if (A >= len) return jump(a, len);
    return jump(b, A + B - len);
}

int solve(int tt) {
    int q; cin >> n >> q;

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 0);

    rep(node, 0, n) {
        up[node][0] = parent[node];
    }

    rep(j, 1, LOG) {
        rep(node, 0, n) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }
    }

    while(q--) {
        int a, b; cin >> a >> b;

        if (a == b) {
            cout << n << nl;
            continue;
        }
        a--; b--;
        int x = lca(a, b);
        int len = level[a] + level[b] - level[x] - level[x];

        ll mid = max(0, len + 1 - 2);
        ll ans = n + 2 * mid + 1 + (mid * (mid - 1))/2;
        
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