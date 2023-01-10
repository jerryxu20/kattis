#include <bits/stdc++.h>
using namespace std;


void build_answer(int &sum, vector<vector<pair<int, int>>> &parents, map<pair<int, int>, int>& num, map<pair<int, int>, int> &weights, int node) {
    if (parents[node].size() == 0) return;
    sort(parents[node].begin(), parents[node].end());
    int mn = parents[node][0].first;
    for (auto p: parents[node]) {
        if (p.first != mn) return;
        sum += 2 * weights[make_pair(min(node, p.second), max(node, p.second))] * num[make_pair(min(node, p.second), max(node, p.second))];
        build_answer(sum, parents, num, weights, p.second);
    }
    return;
}

int main() {
    int P, T;
    cin >> P >> T;
    vector<vector<int>> adj(P);
    map<pair<int, int>, int> weights;
    map<pair<int, int>, int> num;
    for (int i = 0; i < T; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) continue;
        int l = weights[make_pair(min(a, b), max(a,b))];

        if (l == 0) {
            weights[make_pair(min(a, b), max(a,b))] = c;
            num[make_pair(min(a, b), max(a,b))] = 1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        } else if (c < l) {
            weights[make_pair(min(a, b), max(a,b))] = c;
            num[make_pair(min(a, b), max(a,b))] = 1;
        } else {
            num[make_pair(min(a, b), max(a,b))]++;
        }
    }
    vector<int> distance (P, INT_MAX);
    distance[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, 0));
    vector<vector<pair<int, int>>> parents (P);
    int ans = -1;
    vector<int> paths;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int sum = 0;
        int id = p.second;
        if (distance[id] < d) continue;
        for (int &node: adj[id]) {
            if (distance[node] >= d + weights[make_pair(min(id, node), max(id, node))]) {
                distance[node] = d + weights[make_pair(min(id, node), max(id, node))];
                parents[node].push_back(make_pair(distance[node], id));
                pq.push(make_pair(distance[node], node));
            }
        }
    }
    int sum = 0;
    build_answer(sum, parents, num, weights, P - 1);
    cout << sum << endl;
    return 0;
}