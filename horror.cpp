#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, h, l;
    cin >> n >> h >> l;
    queue<int> q;
    vector<vector<int>> adj (n);
    vector<int> horror (n);
    vector<bool> visited (n);
    int ans = -1;
    for (int i = 0; i < h; i++) {
        // these are bad movies
        int id;
        cin >> id;
        ans = max(ans, id);
        q.push(id);
        visited[id] = true;
    }

    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mx = 0;
    while (true) {
        int sz = q.size();
        if (sz == 0) break;
        int nans = INT_MAX;
        for (int _ = 0; _  < sz; _++) {
            int node = q.front();
            q.pop();
            for (int fren: adj[node]) {
                if (!visited[fren]) {
                    q.push(fren);
                    nans = min(nans, fren);
                    visited[fren] = true;
                }
            }
        }
        if (nans != INT_MAX) {
            ans = nans;
        }
        mx++;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}