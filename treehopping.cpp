#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int LOG = 25;
vector<int> adj[MAXN];
int height[MAXN];
int up[MAXN][LOG];

void dfs(int node, int par) {
    up[node][0] = par;

    for (auto &nxt: adj[node]) if (nxt != par) {
        height[nxt] = height[node] + 1;
        dfs(nxt, node);
    }
    return;
}

int jump(int node, int d) {
    for (int i = 0; i < LOG; i++) if (d & (1 << i)) {
        node = up[node][i];
    }
    return node;
}


int lca(int a, int b) {
    if (height[b] > height[a]) {
        swap(a, b);
    }


    a = jump(a, height[a] - height[b]);
    if (a == b) return a;


    for (int i = LOG - 1; i >= 0 ; i--) {
        int aa = up[a][i];
        int bb = up[b][i];
        if (aa != bb) {
            a = aa;
            b = bb;
        }
    }

    return up[a][0];
}


void solve() {
    int n; cin >> n;

    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    height[1] = 1;
    dfs(1, 0);

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i <= n; i++) {
            int x = up[i][j - 1];
            up[i][j] = up[x][j - 1];
        }
    }
    
    vector<int> perm(n);
    for (int &x: perm) cin >> x;    

    for (int i = 1; i < n; i++) {
        int a = perm[i];
        int b = perm[i - 1];

        
        int x = lca(a, b);
        int d = height[a] + height[b] - height[x] * 2;

        if (d > 3) {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
}


int main() {
    int t; cin >> t;
    while(t--) solve();

}