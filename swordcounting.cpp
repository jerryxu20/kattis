#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair


ll choose(ll n, ll k) {
    if (k == 2) {
        return n * (n - 1) / 2;
    }
    return n * (n - 1) * (n - 2) / 6;
}


int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);
    vector<unordered_set<int>> edges(n + 1);
    while (m--) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] < 4) continue;
        for (auto &nxt: adj[i]) {
            if (deg[nxt] < 2) continue;
            ans += choose(deg[i] - 1, 3) * (deg[nxt] - 1); 
        }
    }
    vector<int> nodes (n);
    iota(all(nodes), 1);
    sort(all(nodes), [&] (auto &first, auto &second) {
        return deg[first] < deg[second];
    });
    vector<int> rank(n + 1);
    for (int i = 0; i < n; i++) {
        rank[nodes[i]] = i;
    }
    
    for (int node: nodes) {
        for (auto &node2: adj[node]) {
            if (rank[node2] < rank[node]) continue;
            for (auto &node3: adj[node]) {
                if (node2 == node3) continue;
                if (rank[node3] < rank[node2]) continue;
                if (!edges[node2].count(node3)) continue;
                ans -= 2 * (choose(deg[node] - 2, 2) + choose(deg[node2] - 2, 2) + choose(deg[node3] - 2, 2));
            }
        }
    }
    cout << ans << endl;
    return 0;
}