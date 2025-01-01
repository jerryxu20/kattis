#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    typedef pair<int, int> pi;
    vector<vector<pi>> adj(n);
    vector<pi> edges;

    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b});
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<pi> pq;
    pq.push({INT_MAX, 0});

    vector<int> dis(n);
    dis[0] = INT_MAX;

    vector<int> par(n, -1);
    while(pq.size()) {
        auto [cap, node] = pq.top();
        pq.pop();

        if (dis[node] != cap) continue;
 
        for (auto &[nxt, c]: adj[node]) {
            int ncap = min(c, cap);
            if (dis[nxt] < ncap) {
                dis[nxt] = ncap;
                par[nxt] = node;
                pq.push({ncap, nxt});
            }
        }
    }

    int cur = n - 1;
    vector<int> path;
    while(cur != -1) {
        path.push_back(cur);
        cur = par[cur];
    }

    set<pi> st;
    for (int i = 0; i < path.size(); i++) {
        for (auto &[nxt, _]: adj[path[i]]) {
            int a = -1;
            int b = -1;
            if (i > 0) a = path[i - 1];
            if (i + 1 < path.size()) b = path[i + 1];
            if (nxt != a && nxt != b) st.insert({path[i], nxt});
        }
    }

    vector<int> ans;
    for (int i = 0; i < edges.size(); i++) {
        pi e = edges[i];
        pi er = {e.second, e.first};
        if (st.count(e) || st.count(er)) {
            ans.push_back(i);
        }
    }

    if (ans.size() == 0) {
        cout << "none\n";
        return 0;
    }
    
    for (int &x: ans) {
        cout << x << " ";
    }
    cout << endl;
}