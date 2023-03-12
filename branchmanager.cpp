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

void dfs(int node, vector<vi> &adj, vi &targets, int &ans) {
    int len = sz(targets);
    bool filled = true;
    while(!targets.empty() && node == targets.back()) {
        ans++;
        targets.pop_back();
        filled = true;
    }
    if (targets.empty()) return;
    for (auto &nxt: adj[node]) {
        dfs(nxt, adj, targets, ans);
        while(!targets.empty() && node == targets.back()) {
            ans++;
            targets.pop_back();
            filled = true;
        }
    }
    if (targets.empty()) return;
    // entirely close this off
    if (len == sz(targets)) {
        return;
    }
    if (!filled) {
        targets.pop_back();
    }

    return;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i = 0; i <= n; i++) {
        sort(all(adj[i]));
    }
    vector<int> target(m);
    for (auto &t: target) {
        cin >> t;
    }
    reverse(all(target));
    int ans = 0;
    dfs(1, adj, target, ans);
    cout << ans << endl;
    return 0;
}