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

vi color;
void dfs(int node, vii &adj, vi &order) {
    color[node] = 1;
    trav(nxt, adj[node]) {
        if (color[nxt] == 0) dfs(nxt, adj, order);
    } 
    order.pb(node);
    return;
}

int solve(int tt) {
    int n, a;
    cin >> n;
    vii adj(n);
    vii tadj(n);
    rep(i, 0, n) {
        cin >> a;
        a--;
        adj[i].pb(a);
        tadj[a].pb(i);
    }

    vi order;
    color.assign(n, 0);
    rep(i, 0, n) {
        if (color[i] == 0) dfs(i, adj, order);
    }

    vi comp(n);
    vi nodes;
    color.assign(n, 0);
    int N = 0;
    FORd(i, 0, n) {
        if (color[order[i]] != 0) continue;
        dfs(order[i], tadj, nodes);
        trav(node, nodes) {
            comp[node] = N;
        }
        N++;
        nodes.clear();
    }

    vl ways(n, 0);
    vii adj_scc(N);
    rep(i, 0, n) {
        trav(j, adj[i]) {
            if (comp[i] == comp[j]) continue;
            adj_scc[comp[i]].pb(comp[j]);
        }
    }

    ll ans = 1;
    rep(i, 0, N) {
        if (ways[i] == 0) {
            ways[i] = 1;
        }
        assert(sz(adj_scc[i]) <= 1);
        trav(nxt, adj_scc[i]) {
            if (ways[nxt] > 0) {
                ways[nxt] *= (ways[i] + 1);
                ways[nxt] %= MOD;
            } else {
                ways[nxt] = ways[i] + 1;
                ways[nxt] %= MOD;
            }
        }
        if (sz(adj_scc[i]) == 0) {
            ans *= (ways[i] + 1);
            ans %= MOD;
        }
    }

    ans--;
    assert(ans >= 0);
    ans %= MOD;
    cout << (ans + MOD) % MOD << nl;


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