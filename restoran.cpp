#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;
    vector<int> deg(n + 1);
    while(m--) {
        int a, b; cin >> a >> b;
        a--; b--;
        
        edges.push_back({a, b});

        adj[a].push_back(b);
        adj[b].push_back(a);

        deg[a]++;
        deg[b]++;
    }

    map<pair<int, int>, int> state;
    vector<int> odd;
    
    for (int i = 0; i < n; i++) if (deg[i] % 2 == 1) {
        odd.push_back(i);
        
    }

    if (!odd.empty()) {        
        for (auto &node: odd) {
            adj[n].push_back(node);
            adj[node].push_back(n);
        }
    } 

    vector<int> vis(n + 1);
    vector<int> idx(n + 1);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&] (auto &a, auto &b) {
        if (deg[a] % 2 == deg[b] % 2) {
            return deg[a] > deg[b];
        }
        return (deg[a] % 2) > (deg[b] % 2);
    });

    for (auto &s: idx) if (vis[s] == 0) {
        vector<int> stack;
        stack.push_back(s);
    
        vector<int> tour;
        while(stack.size()) {
    
            auto node = stack.back();
            vis[node] = 1;
            while(adj[node].size() && state.count({adj[node].back(), node})) {
                adj[node].pop_back();
            }
    
            if (adj[node].size()) {
                int nxt = adj[node].back();
                state[{node, nxt}] = 1;
    
                stack.push_back(nxt);
                adj[node].pop_back();
            } else {
                stack.pop_back();
                tour.push_back(node);
            }
        }

        int bit = 0;
        for (int i = 0; i < tour.size() - 1; i++) {
            int a = tour[i];
            int b = tour[i + 1];


            state[{a, b}] = bit;
            state[{b, a}] = bit;
            bit ^= 1;
        }

    }
    
    vector<vector<int>> seen(n, vector<int>(2));
    for (auto &[edge, label]: state) if (edge.first < n && edge.second < n) {
        seen[edge.first][label] = 1;
        seen[edge.second][label] = 1;
    }

    for (auto &node: odd) {
        deg[node]--;
    }

    for (int i = 0; i < n; i++) if (deg[i] >= 2) {
        if (seen[i][0] == 0 || seen[i][1] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    for (auto &[a, b]: edges) {
        int label;
        if (state.count({a, b})) {
            label = state[{a, b}];
        } else {
            label = state[{b, a}];
        }

        cout << label + 1 << endl;
    }
}