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
const int MAXN = 5e4;
int ans = 0;
int n, k;
unordered_set<int> adj[MAXN];

bool valid(vi &nodes) {
    rep(i, 0, sz(nodes)) {
        rep(j, 0, i) {
            if (!adj[nodes[i]].count(nodes[j])) return false;
        }
    }
    return true;
}

void check(int node) {
    vi out(all(adj[node]));
    assert(sz(out) <= k);

    rep(i, 0, 1 << sz(out)) {
        vi nodes = {node};
        rep(j, 0, sz(out)) {
            if (i & (1 << j)) {
                nodes.pb(out[j]);
            }
        }

        if (valid(nodes)) {
            ans = max(ans, sz(nodes));
        }
    }
}


int solve(int tt) {
    cin >> n >> k;

    rep(i, 0, n) {
        int m; cin >> m;
        while(m--) {
            int j; cin >> j;
            adj[i].insert(j);
        }
    }

    PQG<pi> pq;
    rep(i, 0, n) {
        pq.push({sz(adj[i]), i});
    }
    vi done(n);

    while(sz(pq)) {
        auto [_, node] = pq.top();
        pq.pop();
        if (done[node]) continue;

        check(node);
        

        done[node] = 1;
        trav(nxt, adj[node]) {
            adj[nxt].erase(node);
            pq.push({sz(adj[nxt]), nxt});
        }

    }

    cout << ans << nl;

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