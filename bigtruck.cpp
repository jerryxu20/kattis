#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> tii;
#define pb push_back
#define mp make_pair

int n, m, a, b, c;

int main() {
    cin >> n;
    // 1 to n
    vector<int> weights(n + 1);
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
    }
    cin >> m;
    while(m--) {
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    // cost, node
    pq.push({0 , -weights[1], 1});
    vector<int> ans (n + 1, INT_MAX);
    vector<int> mxpick (n + 1, 0);
    ans[1] = 0;
    mxpick[1] = -weights[1];
    while(!pq.empty()) {
        auto [cost, pickup, node] = pq.top();
        pq.pop();
        if (node == n) break;
        if (cost > ans[node]) continue;
        if (pickup > weights[node]) continue;
        for (auto &[nxt, weight]: adj[node]) {
            int new_cost = cost + weight;
            int p = pickup - weights[nxt];
            if (new_cost > ans[nxt]) continue;
            if (mxpick[nxt] <= p) continue;
            mxpick[nxt] = pickup - weights[nxt];
            ans[nxt] = new_cost;
            pq.push({new_cost, mxpick[nxt], nxt});
        }
    }
    if (ans[n] == INT_MAX) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << ans[n] << " " << -mxpick[n] << endl;
    return 0;
}