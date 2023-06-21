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

vii adj;
vi sk, comp, id;
vi contains;
int dt = 0;
int N = 0;

void dfs(int node) {
    int low = id[node] = dt++;
    sk.pb(node);
    trav(nxt, adj[node]) {
        if (id[nxt] == -1) dfs(nxt);
        if (comp[nxt] == -1) low = min(low, id[nxt]);
    }
    if (low == id[node]) {
        int x;
        do {
            x = sk.back();
            sk.pop_back();
            comp[x] = N;
        } while (x != node);
        N++;
    }
    id[node] = low;
    return;
}

vii adj_scc;
vector<set<int>> st;

void dfs2(int node, map<int, int> &s) {
    trav(num, st[node]) {
        s[num]++;
    }
    contains[node] = sz(s);
    trav(nxt, adj_scc[node]) {
        dfs2(nxt, s);
    }
    trav(num, st[node]) {
        if (--s[num] == 0) s.erase(num);
    }
    return;
}

int solve() {
    int n;
    cin >> n;
    adj.resize(n);
    id.resize(n, -1);
    comp.resize(n, -1);
    vi jumps(n);
    trav(j, jumps) cin >> j;


    rep(node, 0, n) {
        int nxt = node + jumps[node];
        if (nxt < 0 || nxt >= n) continue;
        adj[node].pb(nxt);
    }

    rep(i, 0, n) {
        if (id[i] == -1) dfs(i);
    }

    vl rank(N);
    st.resize(N);
    adj_scc.resize(N);
    contains.resize(N);
    rep(i, 0, n) {
        // cout << i << " belongs to " << comp[i] << nl;
        st[comp[i]].insert(jumps[i]);
        rank[comp[i]]++;
        trav(j, adj[i]) {
            if (comp[i] == comp[j]) continue;
            adj_scc[comp[j]].pb(comp[i]);
        }
    }
    ll ans = 0;
    rep(i, 0, N) {
        if (contains[i] == 0) {
            map<int, int> temp;
            dfs2(i, temp);
        }
        ans += rank[i] * contains[i];
    }
    cout << ans << nl;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve()) break;
    }
    T++;
    return 0;
}