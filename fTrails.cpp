#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
 
#define pb push_back
#define mp make_pair


void build_answer(int &sum, vector<vector<pair<int, int>>> &parents, map<pair<int, int>, int>& num, map<pair<int, int>, int> &weights, int node) {
    if (parents[node].size() == 0) return;
    sort(parents[node].begin(), parents[node].end());
    int mn = parents[node][0].first;
    for (auto p: parents[node]) {
        if (p.first != mn) return;
        int w = weights[make_pair(min(node, p.second), max(node, p.second))];
        if (w < 0) continue;
        sum += 2 * weights[make_pair(min(node, p.second), max(node, p.second))] * num[make_pair(min(node, p.second), max(node, p.second))];
        weights[make_pair(min(node, p.second), max(node, p.second))] *= -1;
        build_answer(sum, parents, num, weights, p.second);
    }
    return;
}

int main() {
    int p, t;
    cin >> p >> t;
    vector<vector<int>> trails;
    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) continue;
        trails.pb({min(a, b), max(a, b), c});
    }
    sort(trails.begin(), trails.end());
    map<pair<int, int>, int> dupes;
    map<pair<int, int>, int> length;
    vector<vector<int>> adj (p);
    for (auto &trail: trails) {
        int d = length[mp(trail[0], trail[1])];
        if (d == 0) {
            length[mp(trail[0], trail[1])] = trail[2];
            dupes[mp(trail[0], trail[1])]++;
            adj[trail[0]].pb(trail[1]);
            adj[trail[1]].pb(trail[0]);
        } else if (d == trail[2]) {
            dupes[mp(trail[0], trail[1])]++;
        }
    }
    // distance, node I am reaching
    vector<int> distances (p, INT_MAX);
    distances[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push(mp(0, 0));

    // distance, and who my parent is
    vector<vector<pair<int, int>>> parents (p);
    while (!pq.empty()) {
        auto thing = pq.top();
        pq.pop();
        int id = thing.second;
        int d = thing.first;
        
        if (id == p - 1) continue;
        if (distances[id] < d) continue;
        for (int node: adj[id]) {
            if (distances[node] >= d + length[mp(min(id, node), max(id, node))]) {
                distances[node] =  d + length[mp(min(id, node), max(id, node))];
                parents[node].pb(mp(distances[node], id));
                pq.push(mp(distances[node], node));
            }
        }
    }
    
    int ans = 0;
    build_answer(ans, parents, dupes, length, p - 1);
    cout << ans << endl;

    return 0;
}