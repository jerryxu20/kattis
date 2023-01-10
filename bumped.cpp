#include <bits/stdc++.h>
using namespace std;

#define sz(x) (long long)(x).size()
typedef long long ll;
typedef pair<long long, long long> pii;

#define pb push_back
#define mp make_pair
// solve(plane, roads, r_cost, s, t)
long long solve(vector<long long> &plane, vector<vector<long long>> &roads, map<pair<long long, long long>, long long> &cost, long long start, long long target) {
    long long n = roads.size();
    vector<long long> distance(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    distance[start] = 0;
    pq.push(mp(0, start));
    long long ans = INT_MAX;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        long long d = p.first;
        long long id = p.second;
        if (id == target) {
            ans = d;
            break;
        }
        if (d > distance[id]) continue;
        if (id == plane[0]) {
            if (distance[plane[1]] > d) {
                pq.push(mp(d, plane[1]));
                distance[plane[1]] = d;
            }
        }
        for (long long &node: roads[id]) {
            if (distance[node] > d + cost[mp(min(id, node), max(id, node))]) {
                distance[node] = d + cost[mp(min(id, node), max(id, node))];
                pq.push(mp(distance[node], node));
            }
        } 
    }
    return ans;
}

int main() {
    long long n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;
    // cities, roads, flights, starting, ending
    vector<vector<long long>> roads(n);
    map<pair<long long, long long>, long long> r_cost;
    for (long long i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        roads[a].pb(b);
        roads[b].pb(a);
        r_cost[mp(min(a, b), max(a, b))] = c;
    }
    long long ans = INT_MAX;
    for (long long i = 0; i < f; i++) {
        long long a, b;
        cin >> a >> b;
        vector<long long> plane = {a, b};
        // solve?
        ans = min(ans, solve(plane, roads, r_cost, s, t));

    }
    cout << ans;
    return 0;
}