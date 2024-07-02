#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

vector<int> dijk(int s, vector<vector<pi>> &adj) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dis(adj.size(), INT_MAX);
    pq.push({0, s});
    dis[s] = 0;

    while(pq.size()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (dis[node] != d) continue;
        for (auto &[nxt, w]: adj[node]) {
            int cand = w + d;
            if (dis[nxt] > cand) {
                dis[nxt] = cand;
                pq.push({cand, nxt});
            }
        }
    }

    return dis;
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--; b--;

    vector<vector<pi>> adj(n);
    int sm = 0;
    while(m--) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        sm += c;
    }

    vector<int> to_off = dijk(b, adj);
    vector<int> from_home = dijk(a, adj);

    int keep = 0;
    for (int i = 0; i < n; i++) {
        for (auto &[j, w]: adj[i]) {
            if (from_home[i] == INT_MAX) continue;
            if (to_off[j] == INT_MAX) continue;
            if (from_home[i] + w + to_off[j] == to_off[a]) {
                keep += w;
            }
        }
    }

    cout << sm - keep << endl;
}