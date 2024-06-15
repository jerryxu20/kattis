#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
const int MAXN = 1000;
int dp[MAXN];

int f(int node, vector<int> &dis, vector<vector<pi>> &adj) {
    if (node == 1) return 1;
    int &ans = dp[node];
    if (ans != -1) return ans;
    

    ans = 0;
    for (auto &[nxt, _]: adj[node]) {
        if (dis[nxt] < dis[node]) ans += f(nxt, dis, adj);
    }
    return ans;
}

int solve() {
 int n, m;
    cin >> n;
    if (n == 0) return 1;
    cin >> m;

    memset(dp, -1, n * sizeof(dp[0]));
    vector<vector<pi>> adj(n);
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> dis(n, INT_MAX);
    dis[1] = 0;
    pq.push({0, 1});

    while(pq.size()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (dis[node] != d) continue;
        for (auto &[nxt, w]: adj[node]) {
            int cand = d + w;
            if (cand < dis[nxt]) {
                dis[nxt] = cand;
                pq.push({cand, nxt});
            }
        }
    }

    int ans = f(0, dis, adj);
    cout << ans << endl;
    return 0;
}

int main() {
    while(solve() == 0) {};
}