#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
vector<int> adj[MAXN];
int color[MAXN];

void dfs(int node, int c) {
    color[node] = c;
    for (auto &nxt: adj[node]) if (color[nxt] == -1) {
        dfs(nxt, c ^ 1);
    }
}


int main() {
    int n, m; cin >> n >> m;
    memset(color, -1, sizeof(color));
    while(m--) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) if (color[i] == -1) {
        dfs(i, 0);
    }

    for (int i = 0; i < n; i++) {
        if (adj[i].empty()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (color[i]) cout << "pub ";
        else cout << "house ";
    }
    cout << endl;
}