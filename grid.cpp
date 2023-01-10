#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n);
    vector<vector<bool>> visited (n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c: s) {
            int a = c - '0';
            grid[i].push_back(a);
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    int ans = 0;
    while (true) {
        int sz = q.size();
        if (sz == 0) break;
        for(int _ = 0; _ < sz; _++) {
            auto p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            int d = grid[i][j];
            if (i == n - 1 && j == m - 1) {
                cout << ans;
                return 0;
            }
            if (i + d < n && !visited[i + d][j]) {
                q.push(make_pair(i + d, j));
                visited[i + d][j] = true;
            }
            if (j + d < m && !visited[i][j + d]) {
                q.push(make_pair(i, j + d));
                visited[i][j + d] = true;
            }
            if (i - d >= 0 && !visited[i - d][j]) {
                q.push(make_pair(i - d, j));
                visited[i - d][j] = true;
            }
            if (j - d >= 0 && !visited[i][j - d]) {
                q.push(make_pair(i, j - d));
                visited[i][j - d] = true;
            }
        }
        ans++;
    }
    cout << -1;
}