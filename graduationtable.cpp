#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

int n;
const int MAXN = 5000;
int seen[MAXN];
vector<pl> adj[MAXN];

void dfs(int node, int par, int mn) {
    seen[node] = 1;
    for (auto &[nxt, c]: adj[node]) if (nxt != par) {
        mn = min((int)c, mn);
        if (seen[nxt]) throw mn;
        dfs(nxt, node, mn);
    }
}

int main() {
    int m; cin >> n >> m;
    ll ans = 0;
    while(m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        ans += c;
    }
    int comp = 0;
    ll sub = 0;
    for (int i = 0; i < n; i++) if (!seen[i]) {
        comp++;
        try {
            dfs(i, -1, INT_MAX);
        } catch(int mn) {
            sub += mn;
        }
    }
    if (comp == 1) {
        cout << ans << "\n";
        return 0;
    }
    cout << ans - sub << "\n";
}