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
const int MAXN = 3000;
ti edges[MAXN];
vector<vpi> adj;
int n, m;

int other(int node, int e) {
    auto &[a, b, _] = edges[e];
    if (a == node) return b;
    return a;
}

int bfs(int a, int b) {
    vi take(n, -2);
    queue<int> q;
    q.push(a);
    take[a] = -1;
    while(sz(q)) {
        auto node = q.front();
        q.pop();
        for (auto &[nxt, id]: adj[node]) {
            if (take[nxt] == -2) {
                take[nxt] = id;
                q.push(nxt);
            }
            if (nxt == b) break;
        }
    }

    vi path;

    int cur = b;
    do {
        int e = take[cur];
        path.push_back(e);
        cur = other(cur, e);
    } while(cur != a); 
    
    int ans = path[0];
    int mx = 0;
    for (int &e: path) {
        auto &[_, __, cost] = edges[e];
        if (cost > mx) {
            ans = e;
            mx = cost;
        } 
    }

    return ans;
}

int solve(int tt) {
    cin >> n >> m;
    adj.resize(n);
    rep(i, 0, m) {
        auto &[a, b, cost] = edges[i];
        cin >> a >> b >> cost;
        a--; b--;
    }

    rep(i, 0, n - 1) {
        auto &[a, b, _] = edges[i];
        adj[a].pb({b, i});
        adj[b].pb({a, i});
    }


    vi idx(m);
    iota(all(idx), 0);
    sort(all(idx), [&] (auto &a, auto &b) {
        auto &[_, __, ca] = edges[a];
        auto &[___, ____, cb] = edges[b];
        return ca < cb;
    });

    vpi ans;
    for (int &e: idx) {
        auto &[a, b, cand] = edges[e];
        
        int j = bfs(a, b);

        auto &[u, v, cur] = edges[j];
        if (cand < cur) {
            ans.pb({j, e});

            for (auto &e: adj[u]) {
                if (e.first == v) {
                    swap(adj[u].back(), e);
                    adj[u].pop_back();
                    break;
                }
            }

            for (auto &e: adj[v]) {
                if (e.first == u) {
                    swap(adj[v].back(), e);
                    adj[v].pop_back();
                    break;
                }
            }

            adj[a].pb({b, e});
            adj[b].pb({a, e});
        }
    }

    cout << sz(ans) << nl;
    for (auto &[a, b]: ans) {
        cout << a + 1 << " " << b + 1 << "\n";
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