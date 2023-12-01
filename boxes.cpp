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
int t = 0;
vii adj;
void dfs(int node, vi&t1, vi &t2) {
    t1[node] = t++;
    trav(nxt, adj[node]) {
        dfs(nxt, t1, t2); 
    }
    t2[node] = t;
    return;
}
int solve(int tt) {
    int n; cin >> n;
    adj.resize(n);
    vi root;
    rep(i, 0, n) {
        int par; cin >> par;
        if (par == 0) {
            root.pb(i);
            continue;
        }
        adj[par - 1].pb(i);
    }

    vi t1(n), t2(n);
    trav(r, root) {
        dfs(r, t1, t2);
    }
    vi inside(n, -2);
    int q; cin >> q;
    while(q--) {
        int m; cin >> m;
        vi idx(m);
        trav(i, idx) {
            cin >> i;
            i--;
        }
        trav(i, idx) {
            trav(j, idx) {
                if (i == j) continue;
                // does i contain j
                if (t1[i] < t1[j] && t2[i] >= t2[j]) {
                    inside[j] = q;
                }
                if (t1[j] < t1[i] && t2[j] >= t2[i]) {
                    inside[i] = q;
                }
            }
        }

        ll ans = 0;
        trav(i, idx) {
            if (inside[i] == q) continue;
            ans += t2[i] - t1[i];
            inside[i] = q;
        }
        cout << ans << endl;


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