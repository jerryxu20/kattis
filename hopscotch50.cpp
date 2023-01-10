#include <bits/stdc++.h>
using namespace std;

int mapping(int i, int j, int n) {
    return i * n + j;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> box(k + 2);
    vector<vector<pair<int, int>>> adj (n * n);
    vector<bool> is_end(n * n);
    vector<int> distance(n * n, INT_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a == k) {
                is_end[mapping(i, j, n)] = true;
            }
            for (pair<int, int> &node: box[a + 1]) {
                adj[mapping(i, j, n)].push_back(make_pair(abs(i - node.first) + abs(j - node.second), mapping(node.first, node.second, n)));
            } 
            for (pair<int, int> &node: box[a - 1]) {
                adj[mapping(node.first, node.second, n)].push_back(make_pair(abs(i - node.first) + abs(j - node.second), mapping(i, j, n)));
            }
            box[a].push_back(make_pair(i, j)); 
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (pair<int, int> node: box[1]) {
        int mp = mapping(node.first, node.second, n);
        distance[mp] = 0;
        pq.push(make_pair(0, mp));
    }

    int ans = -1;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (p.first > distance[p.second]) continue;
        if (is_end[p.second]) {
            ans = p.first;
            break;
        }
        for (pair<int, int> & node: adj[p.second]) {
            if (node.first + p.first < distance[node.second]) {
                pq.push(make_pair(node.first + p.first, node.second));
                distance[node.second] = node.first + p.first;
            }
        }
    }
    cout << ans << endl;

    return 0;
}