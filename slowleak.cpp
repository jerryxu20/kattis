#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
const int MAXN = 500;


ll dp[MAXN][MAXN];
vector<pi> adj[MAXN];
int refill[MAXN];
int seen[MAXN];

int main() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    while(k--) {
        int a; cin >> a; a--;
        refill[a] = 1;
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j) {
            dp[i][j] = LLONG_MAX;
        }
    }


    while(m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;        
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] == LLONG_MAX || dp[k][j] == LLONG_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int s = 0;
    int t = n - 1;


    for (int i = 0; i < n; i++) if (refill[i] || i == s) {
        for (int j = 0; j < n; j++) if (refill[j] || j == t) {
            if (dp[i][j] <= d) adj[i].push_back({j, dp[i][j]});
        }

    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});
    vector<ll> dis(n, LLONG_MAX);
    dis[s] = 0;


    while(pq.size()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (d != dis[node]) continue;

        if (node == t) {
            cout << d << endl;
            return 0;
        }

        for (auto &[nxt, w]: adj[node]) {
            ll cand = w + d;
            if (cand < dis[nxt]) {
                dis[nxt] = cand;
                pq.push({cand, nxt});
            }
        }
    }

    cout << "stuck\n";




}