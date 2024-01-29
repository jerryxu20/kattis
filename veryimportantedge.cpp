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

struct UF {
    vi rank, id;
    UF(int n) {
        rank.resize(n, 1);
        id.resize(n);
        iota(all(id), 0);
        return;
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

// Move items from s to t
void move(PQG<ti> &s, PQG<ti> &t) {
    if (sz(t) < sz(s)) swap(s, t);
    
    while(sz(s)) {
        auto x = s.top();
        s.pop();
        t.push(x);
    }

    return;
}

int solve(int tt) {
    int n, m;
    cin >> n >> m;

    vector<ti> edges(m);
    for (auto &[w, a, b]: edges) {
        cin >> a >> b >> w;
        a--; b--;
    }
    sort(all(edges));
    
    vector<PQG<ti>> subtree(n);
    vector<vpi> adj(n);

    UF uf(n);

    ll sm = 0;
    for (auto &[w, a, b]: edges) {
        if (uf.join(a, b) == true) {
            adj[a].pb({b, w});
            adj[b].pb({a, w});
            sm += w;
        } else {
            subtree[a].push({w, a, b});
            subtree[b].push({w, a, b});
        }
    }

    queue<int> q;
    uf = UF(n);

    vi deg(n);
    
    rep(i, 0, n) {
        deg[i] = sz(adj[i]);
        if (deg[i] == 1) {
            q.push(i);
        }
    }

    // What is the most the MST can increase by
    ll ans = 0;
    set<pi> considered;
    while(sz(q)) {
        auto node = q.front();
        assert(deg[node] <= 1);

        q.pop();

        // Remove edges are within the same component
        auto &pq = subtree[node];        
        while(sz(pq)) {
            auto [_, i, j] = pq.top();
            if (uf.find(i) != uf.find(j)) break;
            pq.pop(); 
        }

        // Consider each edge that I haven't considered yet
        for (auto &[nxt, weight]: adj[node]) {

            // We have already considered this edge from the other side
            if (uf.find(nxt) == uf.find(node)) continue;

            auto [cand, _, __] = pq.top();
            ans = max(ans, (ll)cand - weight);                

            // Merge these two nodes
            uf.join(node, nxt);
            move(pq, subtree[nxt]);

            deg[nxt]--;
            if (deg[nxt] == 1) {
                q.push(nxt);
            }
        }
    }

    cout << sm + ans << endl;
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