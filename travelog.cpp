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
const int MAXN = 2e5;


map<int, int> dp[MAXN];
map<int, int> ways[MAXN];

int seen[MAXN];
vi order;
void dfs(int node, vii &adj) {
    seen[node] = 1;
    for (auto &nxt: adj[node]) {
        if (seen[nxt] == 2) continue;
        dfs(nxt, adj);
    }
    seen[node] = 2;
    order.push_back(node);
}

int solve(int tt) {
    int n, m, d; cin >> n >> m >> d;

    vector<vpl> adj(n);
    while(m--) {
        ll a, b, h;
        cin >> a >> b >> h;
        a--; b--;
        adj[a].push_back({b, h});
    }

    vl arr(d);
    for (auto &x: arr) cin >> x;
    sort(all(arr));

    map<ll, ll> idx;
    rep(i, 0, d) {
        idx[arr[i]] = i;
    }
    // arr.clear();

    PQG<pl> pq;
    pq.push({0, 0});

    vl dis(n, LLONG_MAX);
    vii par(n);
    dis[0] = 0;

    while(sz(pq)) {
        auto [node, dd] = pq.top();
        pq.pop();
        if (node == n - 1) break;
        if (dd != dis[node]) continue;

        for (auto &[nxt, w]: adj[node]) {
            ll cand = dd + w;
            if (cand < dis[nxt]) {
                par[nxt].clear();
                dis[nxt] = cand;
                pq.push({nxt, cand});
            }
            if (cand == dis[nxt]) par[nxt].push_back(node);
        }
    }

    vii radj(n);

    rep(i, 0, n) {
        for (int &j: par[i]) {
            radj[j].push_back(i);
        }
    }

    dfs(0, radj);
    reverse(all(order));



    dp[0][-1] = -1;
    ways[0][-1] = 1;
    
    for (auto &node: order) {
        ll dd = dis[node];
        if (idx.count(dd)) {
            int i = idx[dd];

            int a = ways[node][i - 1];
            int b = dp[node][i - 1];

            ways[node].clear();
            dp[node].clear();

            ways[node][i] = a;
            ways[node][i - 1] = a;

            dp[node][i] = b;
            dp[node][i - 1] = b;
            for (auto &nxt: radj[node]) {
                dp[nxt][i] = node;
                ways[nxt][i] += ways[node][i]; 
                ways[nxt][i] = min(ways[nxt][i], 2);
            }
            continue;           
        }
        for (auto &nxt: radj[node]) {
            for (auto &[j, _]: dp[node]) {
                dp[nxt][j] = node;
                ways[nxt][j] += ways[node][j];
                ways[nxt][j] = min(ways[nxt][j], 2);
            }
        }
    }

    int res = ways[n - 1][d - 1];
    if (res == 0) cout << 0 << endl;
    else if (res > 1) cout << 1 << endl;
    else {
        vector<int> ans;
        int node = n - 1;
        int i = d - 1;
        do {
            ans.push_back(node);
            if (idx.count(dis[node])) i--;
            node = dp[node][i];
        } while(node != -1);
        reverse(all(ans));
        cout << sz(ans) << nl;
        for (auto &x: ans) {
            cout << x + 1 << endl;
        }
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