#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, m; cin >> n >> m;

    vector<vector<pi>> adj(n);
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    vector<int> dis(n, INT_MAX);
    pq.push({0, 1});
    dis[1] = 0;
    
    while(pq.size()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (d != dis[node]) continue;

        for (auto &[nxt, w]: adj[node]) {
            int cand = d + w;
            if (cand < dis[nxt]) {
                dis[nxt] = cand;
                pq.push({cand, nxt});
            }
        }
    }

    vector<int> par(n, -1);
    par[0] = 0;

    queue<int> q;
    q.push(0);

    while(q.size()) {
        auto node = q.front();
        q.pop();

        for (auto &[nxt, w]: adj[node]) {
            if (dis[node] == w + dis[nxt] || par[nxt] != -1) continue;
            par[nxt] = node;
            q.push(nxt);
        }
    }

    if (par[1] == -1) {
        cout << "impossible\n";
        return 0;
    }

    int cur = 1;

    vector<int> path;

    do {
        path.push_back(cur);
        cur = par[cur];
    } while (cur != 0);
    path.push_back(0);
    reverse(path.begin(), path.end());
    
    cout << path.size() << " ";
    for (int &x: path) {
        cout << x << " ";
    }
    cout << endl;


}