#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

void djikstra(vector<vector<pair<int, int>>> &adj, vector<int> &d, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(mp(0, 0));
    d[0] = 0;
    int node, weight;
    int a, dis;
    while (!pq.empty()) {
        tie (a, dis) = pq.top();
        pq.pop();
        if (d[a] < dis) continue;
        for (auto &p: adj[a]) {
            tie (node, weight) = p;
            int nd = dis + weight;
            if (nd < d[node]) {
                pq.push(mp(node, nd));
                d[node] = nd;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> nums(N);
    vector<ll> queries(M);
    int mn = INT_MAX;
    for (int &num: nums) {
        cin >> num;
        mn = min(num, mn);
    }
    for (ll &q: queries)
        cin >> q;

    vector<vector<pair<int, int>>> adj(mn);
    for (int i = 0; i < mn; i++) {
        for (int num: nums) {
            int nxt = (i + num) % mn;
            adj[i].pb(mp(nxt, num));
        }
    }
    vector<int> d (mn, INT_MAX);
    djikstra(adj, d, 0);
    for (int q: queries) {
        if (d[q % mn] <= q) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    return 0;
}