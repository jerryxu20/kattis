#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

#define trav(x,A) for (auto& x : A)
#define pb push_back
typedef vector<int> vi;


unordered_map<string, int> ID;
vi color;
int N = 0;
int id(string s) {
    if (ID.count(s)) return ID[s];
    ID[s] = N++;
    return ID[s];
}

void dfs(int node, vector<vi> &adj, vi &order) {
    color[node] = 1;
    trav(nxt, adj[node]) {
        if (color[nxt] == 0) dfs(nxt, adj, order); 
    }
    order.pb(node);
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int m, n; cin >> m >> n;

    vector<tuple<int, int, int>> edges;

    string a, b;
    int u, v;
    rep(i, 0, m) {
        cin >> a >> b;
        u = id(a);
        v = id(b);
        edges.pb({u, v, 0});
    }
    rep(i, 0, n) {
        cin >> a >> b;
        u = id(a);
        v = id(b);
        edges.pb({u, v, 1});
    }
    vector<vector<int>> adj(N);
    vector<vector<int>> t_adj(N);
    for (auto &[a, b, _]: edges) {
        adj[a].pb(b);
        t_adj[b].pb(a);
    }
    color.resize(N);
    vi order(N);
    rep(i, 0, N) {
        if (color[i] == 0) dfs(i, adj, order);
    }

    reverse(all(order));
    color.assign(N, 0);
    vi cont;
    vi comp(N);
    int cnt = 0;
    trav(node, order) {
        if (color[node] != 0) continue;
        dfs(node, t_adj, cont);
        trav(c, cont) {
            comp[c] = cnt;
        }
        cnt++;
        cont.clear();
    }

    vector<vector<pair<int, int>>> r_adj(N);

    for (auto &[a, b, c]: edges) {
        if (comp[a] == comp[b]) continue;
        r_adj[comp[a]].pb(make_pair(comp[b], c));
    }

    vector<int> ans(cnt, -1);
    int mn = 0;
    for (int i = 0; i < cnt; i++) {
        if (ans[i] == -1) ans[i] = 1;
        mn = max(mn, ans[i]);
        for (auto &[nxt, kind]: r_adj[i]) {
            int cand = ans[i] + kind;
            ans[nxt] = max(ans[nxt], cand);
        }
    }
    cout << mn << " " << cnt << '\n';
}