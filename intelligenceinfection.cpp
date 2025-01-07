#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4;
vector<int> adj[MAXN], t_adj[MAXN];
int seen[MAXN], opp[MAXN], connected_opp[MAXN];

void dfs_op(int node) {
    connected_opp[node] = 1;
    for (auto &nxt: t_adj[node]) {
        if (connected_opp[nxt] == 0) dfs_op(nxt);
    }
    return;
}

void dfs(int node, vector<int> &order) {
    seen[node] = 1;
    for (auto &nxt: adj[node]) {
        if (seen[nxt] == 0) dfs(nxt, order);
    }
    seen[node] = 2;
    order.push_back(node);
}

int main() {
    int n, m, k; cin >> n >> k >> m;

    while(m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        t_adj[b].push_back(a);
    }

    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        opp[x] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (opp[i] && connected_opp[i] == 0) dfs_op(i);
    }

    vector<int> order;
    for (int i = 0; i < n; i++) {
        if (seen[i] == 0) dfs(i, order);
    }
    reverse(order.begin(), order.end());

    memset(seen, 0, sizeof(seen));
    int ans = 0;
    for (int &node: order) if (!opp[node] && seen[node] == 0) {
        ans++;
        if (connected_opp[node] == 0) {
            vector<int> _;
            dfs(node, _);
        }
    }

    cout << ans << endl;

}
