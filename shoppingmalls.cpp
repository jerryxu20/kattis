#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> ti;

const int MAXN = 200;
const double MX = 1e9;
int x[MAXN], y[MAXN], z[MAXN];

double dis(int dx, int dy, int dz) {
    return sqrt(dx * dx + dy * dy + dz * dz);
}

vector<pair<int, double>> adj[MAXN];

double dp[MAXN][MAXN];
int part[MAXN][MAXN];

void dfs(int a, int b, vector<int> &path) {
    if (a == b) {
        path.push_back(a);
        return;
    }
    if (part[a][b] == -1) {
        path.push_back(a);
        path.push_back(b);
        return;
    }

    int k = part[a][b];
    
    dfs(a, k, path);
    path.pop_back();
    dfs(k, b, path);
}

int main() {
    memset(part, -1, sizeof(part));
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> z[i] >> x[i] >> y[i];
        z[i] *= 5;
    }

    while(m--) {
        int a, b; cin >> a >> b;
        

        string type; cin >> type;
        if (type == "walking" || type == "stairs") {
            adj[a].push_back({b, dis(x[a] - x[b], y[a] - y[b], z[a] - z[b])});
            adj[b].push_back({a, dis(x[a] - x[b], y[a] - y[b], z[a] - z[b])});
        } else if (type == "lift") {
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 1});
        } else {
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 3 * dis(x[a] - x[b], y[a] - y[b], z[a] - z[b])});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = MX;
        }
    }
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int i = 0; i < n; i++) {
        for (auto &[nxt, d]: adj[i]) {
            dp[i][nxt] = min(dp[i][nxt], d);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double cand = dp[i][k] + dp[k][j];
                if (cand < dp[i][j]) {
                    dp[i][j] = cand;
                    part[i][j] = k;
                }
            }
        }
    }

    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        vector<int> ans;
        dfs(a, b, ans);
        for (int &x: ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}