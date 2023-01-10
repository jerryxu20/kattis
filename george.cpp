#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    int n, m;
    cin >> n >> m;
    int s, t, k, g;
    cin >> s >> t >> k >> g;
    vector<ll> george(g);
    for (int i = 0; i < g; i++) {
        cin >> george[i];
    }
    vector<vector<pair<ll, ll>>> adj(n + 1);
    map<pair<ll, ll>, ll> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
        edges[mp(a, b)] = c;
        edges[mp(b, a)] = c;
    }
    ll time = -k; 
    map<pair<ll, ll>, ll> time_requirement;
    for (int i = 0; i + 1 < g; i++) {
        ll g1 = george[i];
        ll g2 = george[i + 1];
        time_requirement[mp(g2, g1)] = time;
        time_requirement[mp(g1, g2)] = time;
        time += edges[mp(g1, g2)];

    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(mp(0, s));
    vector<ll> distance (n + 1, LLONG_MAX);
    distance[s] = 0;
    ll ans = 0;
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        ll d = p.first;
        ll node = p.second;
        if (node == t) {
            ans = d;
            break;
        }
        if (distance[node] < d) continue;
        for (auto &edge: adj[node]) {
            ll t_time = d + edge.second;
            if (time_requirement.count(mp(node, edge.first))) {
                ll tr = time_requirement[mp(node, edge.first)];
                if (!(d >= tr + edge.second || d < tr)) {
                    t_time = tr + edge.second + edge.second;
                }
            }

            if (distance[edge.first] > t_time) {
                // cout << node << " " << edge.first << " " << t_time << endl;
                pq.push(mp(t_time, edge.first));
                distance[edge.first] = t_time;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}