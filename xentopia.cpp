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
typedef tuple<ll, ll, ll> ti;
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

int solve(int tt) {
    int n, m; cin >> n >> m;
    int k1, k2; cin >> k1 >> k2;

    vector<vector<ti>> adj(n + 1);
    while(m--) {
        int u, v, cost, color;
        cin >> u >> v >> cost >> color;
        adj[u].pb({v, cost, color});
        adj[v].pb({u, cost, color});
        // white is 0, red is 1, blue is 2.
        // k1 red, k2 blue
    }
    int s, t;
    cin >> s >> t;
    // vector<vector<vl>> dis(n + 1, vector<vl>(k1 + 1, vl(k2 + 1, LLONG_MAX)));
    vector<map<int, map<int, ll>>> dis(n + 1);
    dis[s][0][0] = 0;
    PQG<tuple<ll, ll, ll, ll>> pq;
    pq.push({0, s, 0, 0});
    while(sz(pq)) {
        auto [d, node, red, blue] = pq.top();
        pq.pop();
        if (dis[node][red][blue] != d) continue;
        if (node == t && red == k1 && blue == k2) {
            cout << d << nl;
            return 0;
        }
        for (auto &[nxt, cost, color]: adj[node]) {
            if (color == 1 && red == k1) continue;
            if (color == 2 && blue == k2) continue;
            int r = red + (int)(color == 1);
            int b = blue + (int)(color == 2);

            if (dis[nxt].count(r) && dis[nxt][r].count(b) && dis[nxt][r][b] <= cost + d) continue;
            // if (dis[nxt][r][b] <= cost + d) continue;
            dis[nxt][r][b] = cost + d;
            pq.push({cost + d, nxt, r, b});  
        }
    }
    cout << -1 << nl;


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