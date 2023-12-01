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

vi subtree, low;
vii adj;
int ans = 0, ans2 = 0, tin = 0;
void dfs(int node, int par) {
    int id, reach;
    id = reach = low[node] = ++tin;
    int cnt = 0;
    vi chunks;
    bool art = false;
    bool root = par == -1;
    trav(nxt, adj[node]) if (nxt != par) {
        if (low[nxt] == -1) {
            dfs(nxt, node);
            if (low[nxt] >= id && !root) art = true;
            
            chunks.pb(subtree[nxt]);
            subtree[node] += subtree[nxt];

            cnt++;
        }
        reach = min(reach, low[nxt]);
    }

    low[node] = reach;
    
    if (root && cnt > 1) art = true;
    if (!art) return;

    // this is a cut point
    int mx = 0;
    int sm = 0;
    chunks.pb(sz(adj) - subtree[node]);
    rep(i, 0, sz(chunks)) {
        rep(j, 0, i) {
            int pairs = chunks[i] * chunks[j];
            mx = max(pairs, mx);
            sm += pairs;
        }
    }
    if (sm > ans) {
        ans = sm;
        ans2 = sm - mx;
    }
    return;
}


int solve(int tt) {
    int n; cin >> n;
    adj.resize(n + 1);
    rep(i, 0, n) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // print # of pairs that get disconnected by destroying one junction, and 
    subtree.resize(n + 1, 1);
    low.resize(n + 1, - 1);
    dfs(0, -1);
    cout << ans << " " << ans2 << nl;
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