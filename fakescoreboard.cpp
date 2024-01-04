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

int T, P;

struct Edge {
    int a, b, cap, cur;
    int room() {
        return cap - cur;
    }
};

struct EdmondsKarp {
    vii adj;
    vi par;
    vector<Edge> edges;
    queue<int> q;

    EdmondsKarp(int n) {
        adj.resize(n);
        par.resize(n);
    }

    void add_edge(int a, int b, int cap) {
        edges.pb({a, b, cap, 0});
        edges.pb({b, a, 0, 0});
        adj[a].pb(sz(edges) - 2);
        adj[b].pb(sz(edges) - 1);
    }

    int calc(int s, int t) {
        int flow, ans = 0;
        do {
            flow = bfs(s, t);
            ans += flow;
        } while(flow != 0);
        return ans;
    }

    int bfs(int s, int t) {
        par.assign(sz(adj), -1);
        q.push(s);
        par[s] = 0;

        while(sz(q)) {
            auto node = q.front();
            q.pop();
            trav(i, adj[node]) {
                auto e = edges[i];
                if (e.room() <= 0 || par[e.b] != -1) continue;

                par[e.b] = i;
                q.push(e.b);
            }
        }

        int node = t;
        int ans = INT_MAX;
        do {
            if (par[node] == -1) return 0;
            ans = min(ans, edges[par[node]].room());
            node = edges[par[node]].a;
        } while(node != s);

        node = t;
        do {
            auto &e = edges[par[node]];
            auto &op = edges[par[node] ^ 1];
            e.cur += ans;
            op.cur -= ans; 
            node = e.a;
        } while(node != s);
        return ans;
    }
    
    int remove(int a, int b, int s, int t) {
        int id = (a * P + b) * 2;
        edges[id].cap = 0;
        if (edges[id].cur == 0) {
            return 1;
        };

        vi idx = {adj[s][a], adj[a][b], adj[b + T].back()};

        // Remove flow from the path
        for (int i: idx) {
            edges[i].cur -= 1;
            edges[i^1].cur += 1;
        }

        int ans = calc(s, t);

        // It was not possible to recover the flow, so either add it back
        // or change the capacities to ignore the path. I change the capacities
        if (ans == 0) {
            edges[idx[0]].cap--;
            edges[idx[2]].cap--;
        }
        return ans;
    }
};

vi solved, cap;

int solve(int tt) {
    cin >> T >> P;
    if (T == 0 && P == 0) return 1;

    // T teams and P problems
    solved.resize(T);
    cap.resize(P);
    trav(a, solved) cin >> a;
    trav(a, cap) cin >> a;
 

    int target = accumulate(all(cap), 0);
    int sm = accumulate(all(solved), 0);

    vii adj(T, vi(P, 1));

    int N = T + P + 2;
    int s = N - 2;
    int t = N - 1;
    EdmondsKarp flow(N);
    rep(i, 0, T) {
        rep(j, 0, P) {
            if (adj[i][j]) {
                flow.add_edge(i, j + T, 1);
            }
        }
    }

    rep(i, 0, T) {
        flow.add_edge(s, i, solved[i]);
    }

    rep(j, 0, P) {
        flow.add_edge(j + T, t, cap[j]);
    }

    
    if (target != sm || flow.calc(s, t) != target) {
        cout << "Impossible\n\n";
        return 0;
    }

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < P; j++) {
            adj[i][j] = 0;
            int res = flow.remove(i, j, s, t);
            if (res == 0) {
                adj[i][j] = 1;
            }
        }
    }

    rep(i, 0, T) {
        rep(j, 0, P) {
            cout << (adj[i][j] ? 'Y': 'N');
        }
        cout << nl;
    }
    cout << nl;

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    return 0;


}