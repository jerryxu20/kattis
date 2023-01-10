#include <bits/stdc++.h>
using namespace std;

#define sz(x) (long long)(x).size()
typedef long long ll;
typedef pair<long long, long long> pii;

#define pb push_back
#define mp make_pair

long long solve(vector<vector<pair<long long, long long>>> &adj, vector<vector<long long>> &flights, long long start, long long ending) {
    long long n = adj.size();
    vector<long long> distance(n, LONG_LONG_MAX);
    distance[start] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push(mp(0, start));
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        long long id = p.second;
        long long d = p.first;
        if (id == ending) {
            return d;
        }
        if (d > distance[id]) continue;
        for (int node: flights[id]) {
            if (distance[node] > d) {
                distance[node] = d;
                pq.push(mp(distance[node], node));
            }
        }
        for (auto node: adj[id]) {
            if (distance[node.first] > d + node.second) {
                distance[node.first] = d + node.second;
                pq.push(mp(distance[node.first], node.first));
            }
        }
    }
    return LONG_LONG_MAX;
}

int main() {
    long long n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;
    vector<vector<pair<long long, long long>>> adj(n);
    vector<vector<long long>> flights(n);
    for (long long i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    long long ans = LONG_LONG_MAX;
    for (long long i = 0; i < f; i++) {
        long long a, b;
        cin >> a >> b;
        flights[a].pb(b);
        ans = min(ans, solve(adj, flights, s, t));
    }
    cout << ans;
    return 0;
}