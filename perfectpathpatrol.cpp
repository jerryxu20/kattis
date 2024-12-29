#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5;
vector<pair<ll, ll>> adj[MAXN];
ll F[MAXN], M[MAXN];

void dfs(int node, int par) {
    vector<ll> pushed_up;
    for (auto &[nxt, weight]: adj[node]) if (nxt != par) {
        dfs(nxt, node);

        if (F[nxt] < weight) {
            ll x = (weight - F[nxt]);
            ll cap = min(M[nxt], x/2);
            M[nxt] -= cap;
            F[nxt] += 2 * cap;
            x -= 2 * cap;
            F[nxt] += x;
        }
        F[nxt] -= weight;
        pushed_up.push_back(weight);
    }

    // pair excess nodes
    ll sm = 0;
    ll mx = 0;
    for (auto &x: pushed_up) {
        sm += x;
        mx = max(mx, x);
    }

    F[node] = sm;
    if (mx > sm - mx) {
        M[node] += sm - mx;
        F[node] -= 2 * (sm - mx);
    } else {
        M[node] += sm/2;
        F[node] -= sm/2 * 2;
    }
    return;
}


int main() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        ll a, b, p;
        cin >> a >> b >> p;
        adj[a].push_back({b, p});
        adj[b].push_back({a, p});
    }

    dfs(0, -1);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += M[i] + F[i];
    }
    cout << ans << endl;
}