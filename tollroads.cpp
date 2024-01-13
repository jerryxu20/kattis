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

int level[MAXN], parent[MAXN], firstjump[MAXN], mx[MAXN][LOG], up[MAXN][LOG];

void dfs(int node, int par, vector<vpi> &adj) {
    // cout << "DFS " << node << endl;
    for (auto &[nxt, cost]: adj[node]) if (nxt != par) {
        level[nxt] = level[node] + 1;
        parent[nxt] = node;
        firstjump[nxt] = cost;
        dfs(nxt, node, adj);
    }
}

struct UF {
    vi rank, id;
    UF(int n) {
        rank.resize(n, 1);
        id.resize(n);
        iota(all(id), 0);
        return;
    }
    int find(int a) {
        if (a == id[a]) return a;
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

int max_on_path(int a, int b) {
    if (level[a] > level[b]) swap(a, b);

    int ans = 0;
    int x = level[b] - level[a];
    rep(i, 0, LOG) {
        if (x & (1 << i)) {
            ans = max(ans, mx[b][i]);
            b = up[b][i];
        }
    }

    if (a == b) return ans;
    FORd(i, 0, LOG) {
        int aa = up[a][i];
        int bb = up[b][i];
        if (aa != bb) {
            ans = max({ans, mx[a][i], mx[b][i]});
            a = aa;
            b = bb;
        }
    }
    ans = max({ans, mx[a][0], mx[b][0]});
    return ans;
}

int solve(int tt) {
    int n, m, q; cin >> n >> m >> q;

    vector<ti> edges;

    int a,b,c;
    while(m--) {
        cin >> a >> b >> c;
        a--; b--;
        edges.pb({c, a, b});
    }

    UF uf(n);
    sort(all(edges));
    vector<vpi> adj(n);
    for (auto &[c, a, b]: edges) {
        if (uf.join(a, b)) {
            adj[a].pb({b, c});
            adj[b].pb({a, c});
            // cout << "edges " << a << " " <<b << " " << c << endl;
        }
    }

    dfs(0, 0, adj);

    // rep(i, 0, n) {
    //     cout << parent[i] << " ";
    // }
    // cout << endl;

    // rep(i, 0, n) {
    //     cout << firstjump[i] << " ";
    // }
    // cout << endl;


    rep(i, 0, n) {
        up[i][0] = parent[i];
        mx[i][0] = firstjump[i];
    }

    rep(j, 1, LOG) {
        rep(i, 0, n) {
            up[i][j] = up[up[i][j - 1]][j - 1];
            mx[i][j] = max(mx[i][j - 1], mx[up[i][j - 1]][j - 1]);

        }
    }

    vpi res(q);

    vpi query;
    rep(i, 0, q) {
        cin >> a >> b;
        a--; b--;
        query.pb(mp(a, b));


        // path from a to b

        int ans = max_on_path(a, b);
        res[i].first = ans;
    }

    // cout << "answered jump" << endl;

    vi idx(q); 
    iota(all(idx), 0);
    sort(all(idx), [&] (auto &a, auto &b) {
        return res[a].first < res[b].first;
    });
    // cout << "sorted" << endl;

    
    uf = UF(n);
    edges.pb({INT_MAX, 0, 0});
    int low = 0;
    for (auto &[c, a, b]: edges) {
        while(low < q && c > res[idx[low]].first) {
            int node = query[idx[low]].first;
            res[idx[low]].second = uf.rank[uf.find(node)];
            low++;
        }

        uf.join(a, b);
    }

    for (auto &[x, y]: res) {
        cout << x << " " << y << nl;
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