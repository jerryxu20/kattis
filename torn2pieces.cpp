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

map<string, int> ID;
vs name;
int N = 0;
int id(string &s) {
    if (!ID.count(s)) {
        ID[s] = N++;
        name.pb(s);
    }
    return ID[s];
}

vi pull(string &s) {
    vi ans;
    string cur = "";
    s.pb(' ');
    trav(c, s) {
        if (c == ' ') {
            ans.pb(id(cur));
            cur = "";
            continue;
        }
        cur.pb(c);
    }
    return ans;
}

bool dfs(int node, int t, int par, vi &path, vii &adj) {
    path.pb(node);
    if (node == t) return true;

    trav(nxt, adj[node]) {
        if (nxt == par) continue;
        if (dfs(nxt, t, node, path, adj)) return true;
    }
    path.pop_back();
    return false;
}

int solve(int tt) {
    int n; cin >> n;
    vii adj(100);

    string s;
    getline(cin, s);

    rep(i, 0, n) {
        getline(cin, s);
        vi nodes = pull(s);
        rep(j, 1, sz(nodes)) {
            adj[nodes[0]].pb(nodes[j]);
            adj[nodes[j]].pb(nodes[0]);
        }
        // cout << s << endl;
    }

    string a, b;
    cin >> a >> b;

    int u = id(a);
    int v = id(b);


    vi path;
    if (!dfs(u, v, -1, path, adj)) {
        cout << "no route found\n";
        return 0;
    }

    trav(node, path) {
        cout << name[node] << " ";
    }
    cout << endl;
    


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