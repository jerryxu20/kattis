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
    vector<int> allowed;
    int time = 1;
    vi seen;

    EdmondsKarp(int n) {
        adj.resize(n);
        par.resize(n);
        seen.resize(n);
    }

    void add_edge(int a, int b, int cap) {
        edges.pb({a, b, cap, 0});
        edges.pb({b, a, 0, 0});
        adj[a].pb(sz(edges) - 2);
        adj[b].pb(sz(edges) - 1);
        allowed.pb(1);
        allowed.pb(1);
    }

    int calc(int s, int t) {
        int flow, ans = 0;
        do {
            flow = bfs(s, t, INT_MAX);
            ans += flow;
            time += 1;
        } while(flow != 0);
        return ans;
    }

     int bfs(int node, int t, int flow) {
        if (node == t) return flow;
        
        seen[node] = time;
        trav(i, adj[node]) {
            Edge &e = edges[i];
            if (e.room() == 0 || seen[e.b] == time || !allowed[i]) continue;

            int cap = bfs(e.b, t, min(e.room(), flow));
            if (cap == 0) continue;
            Edge &op = edges[i^1];

            e.cur += cap;
            op.cur -= cap;
            return cap;

        }
        return 0;
    }
    
    int augment(int a, int b, int s, int t) {
        //delete edge a, b
        int id = (a * P + b) * 2;
        // cout << "force edge " << id << endl;
        assert(edges[id].a  == a && edges[id].b == b + T);

        if (edges[id].cur == 1) {
            // cout << id << " was changed " << endl;
            assert(dfs(s, a));
            assert(dfs(b + T, t));
            edges[id].cur--;
            edges[id^1].cur++;
        } else {
            allowed[id] = 0;
            allowed[id ^ 1] = 0;
            return 1;
        }

        assert(edges[id].cur == 0);

        // disallow these edges
        allowed[id] = 0;
        allowed[id ^ 1] = 0;

        // see if we can recover this lost flow
        return calc(s, t);
    }

    int reinstate(int a, int b, int s, int t) {
        int id = (a * P + b) * 2;
        assert(adj[a][b] == id);
        // allowed[id] = 1; 
        // allowed[id ^ 1] = 1;
    
        vi idx = {adj[s][a], adj[a][b], adj[b + T].back()};
        

        for (int i: idx) {
            allowed[i] = 1;
            allowed[i^1] = 1;
            edges[i].cur += 1;
            edges[i^1].cur -= 1;
            // cout << i << endl;
        }
        // cout << endl;
        
        return 1;
    }

    int dfs(int node, int b) {
        if (node == b) return 1;
        // cout << "dfs " << node << endl;
        trav(i, adj[node]) {
            auto &e = edges[i];
            if (e.cur < 1 || !allowed[i]) continue;
            if (dfs(e.b, b) == 0) continue; 
            auto &op = edges[i ^ 1];
            e.cur -= 1;
            op.cur += 1;
            // cout << "edge " << i << " taken" << endl;
            // cout << i << " was changed " << endl;
            // cout << node << " good" << endl;
            return 1;
        }
        // cout << node << " bad" << endl;
        return 0;
    }

};

vi solved, cap;
// ll work(vii &adj) {

//     // cout << ans << endl;
//     return ans;
// }

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
    // V = 160
    // E = 6400

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
            int res = flow.augment(i, j, s, t);
            if (res == 0) {
                adj[i][j] = 1;
                res = flow.reinstate(i, j, s, t);
                assert(res == 1);
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

    // we want no's if possible 

    // at the start there are edges from every team to every problem
    // then find the first yes, and remove that edge, then run flow again
    // finding edges then removing is sketchy


    // start with no edges, run flow
    // if it's not possible, add the last edge, run it again, 
    // there's no removing edges, just adding, so this is okay?
    // no, this is still bad because there will no flow until the first node is activated. 

    // T * P * dinics





    tt++;
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
    T++;
    return 0;
}