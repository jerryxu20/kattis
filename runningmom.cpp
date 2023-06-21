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

vi stk, comp, id;
int N = 0;
int ncomp = 0;
vii adj;
void dfs(int node) {
    int low = id[node] = N++;
    stk.pb(node);
    trav(nxt, adj[node]) {
        if (id[nxt] == -1) dfs(nxt);
        if (comp[nxt] == -1) low = min(low, id[nxt]);
    }
    if (low == id[node]) {
        int x;
        do {
            x = stk.back();
            stk.pop_back();
            comp[x] = ncomp;
        } while (x != node);
        ncomp++;
    }
    id[node] = low;
    return;
}

int solve(int tt) {
    int n; string a, b;
    cin >> n;
    int cnt = 0;
    map<string, int> cast;
    adj.resize(n);
    id.resize(n, -1);
    comp.resize(n, -1);
    rep(i, 0, n) {
        cin >> a >> b;
        if (!cast.count(a)) cast[a] = cnt++;
        if (!cast.count(b)) cast[b] = cnt++;
        adj[cast[a]].pb(cast[b]);
    }
    rep(i, 0, n) {
        if (id[i] == -1) dfs(i);
    }
    vi rank(ncomp);
    vii adj_scc(ncomp);
    rep(i, 0, n) {
        rank[comp[i]]++;
        trav(j, adj[i]) {
            if (comp[i] == comp[j]) continue;
            adj_scc[comp[i]].pb(comp[j]);
        }
    }

    vb safe(ncomp);
    rep(i, 0, ncomp) {
        if (rank[i] > 1) safe[i] = true;
        trav(nxt, adj_scc[i]) {
            if (safe[nxt]) safe[i] = true;
        }
    }    
    
    while(cin >> a) {
        int node = comp[cast[a]];
        cout << a;
        if (safe[node]) cout << " safe\n";
        else cout << " trapped\n";
    }
    
    

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}