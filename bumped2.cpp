#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

int main() {
    int n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;
    // t is target;
    // s is starting
    vector<vector<pair<long long, long long>>> adj(n);
    vector<vector<long long>> flights(n);
    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    for (int i = 0; i < f; i++) {
        long long a, b;
        cin >> a >> b;
        flights[a].push_back(b);
    }
    vector<vector<long long>> d (2, vector<long long> (n, LONG_LONG_MAX));
    priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
    pq.push({0, s, 0});
    long long ans = 0;
    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        long long distance = v[0];
        long long node = v[1];
        long long flied = v[2];
        if (d[flied][node] < distance) {
            continue;
        }
        if (node == t) {
            ans = distance;
            break;
        }
        if (flied == 0) {
            for (long long city: flights[node]) {
                if (d[flied][city] > distance) {
                    d[1][city] = distance;
                    pq.push({distance, city, 1});
                }
            }
        }
        for (auto city: adj[node]) {
            if (d[flied][city.first] > distance + city.second) {
                d[flied][city.first] = distance + city.second;
                pq.push({distance + city.second, city.first, flied});
            } 
        }
    }
    cout << ans << endl;
    return 0;
}