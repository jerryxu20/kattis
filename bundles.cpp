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

void dfs(int node, vii &adj, vi &seen, vi &order) {
    seen[node] = 1;
    trav(nxt, adj[node]) {
        if (seen[nxt] == 0) dfs(nxt, adj, seen, order);
    }
    order.pb(node);
    return;
}

int relate(set<int> &A, set<int> &B) {
    bool disjoint = true;
    trav(a, A) {
        if (B.count(a)) {
            disjoint = false;
            break;
        }
    }
    if (disjoint) return -1;
    if (sz(A) == sz(B)) return 2;
    return ll(sz(A) < sz(B));
}

int solve(int tt) {
    int n, m; cin >> n >> m;

    map<vi, int> cost;
    rep(i, 0, m) {
        int price;
        cin >> price;
        int x; cin >> x;
        vi arr(x);
        trav(a, arr) cin >> a;
        sort(all(arr));
        if (cost.count(arr)) {
            cost[arr] = min(cost[arr], price);
        } else {
            cost[arr] = price;
        }
    }
    vi price;
    vector<set<int>> st;
    for (auto &[a, b]: cost) {
        price.pb(b);
        st.push_back(set<int>(all(a)));
        
    }
    m = sz(price);
     
    // a -> b, means b contains a
    vii adj(m);
    rep(i, 0, m) {
        rep(j, 0, i) {
            int r = relate(st[i], st[j]);
            if (r == 1) {
                adj[i].pb(j);
            } else if (r == 0) {
                adj[j].pb(i);
            }
            assert(r != 2);
        }
    }

    trav(row, adj) {
        sort(all(row), [&](auto &a, auto &b) {
            return sz(st[a]) < sz(st[b]);
        });
    }

    vi order, seen(m);
    rep(i, 0, m) {
        if (seen[i] == 0) dfs(i, adj, seen, order);
    }
    reverse(all(order));

    vector<int> child_cost(m);
    vector<set<int>> cont(m);
    int ans = 0;
    trav(i, order) {
        // my children can cover me entirely
        if (sz(cont[i]) == sz(st[i])) {
            price[i] = min(price[i], child_cost[i]);
        }

        trav(nxt, adj[i]) {
            cont[nxt].insert(all(st[i]));
            child_cost[nxt] += price[i];
            break;
        }

        if (sz(adj[i]) == 0) ans += price[i];
    }
    cout << ans << nl;


    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}