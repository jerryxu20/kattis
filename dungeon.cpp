#include <bits/stdc++.h>
using namespace std;

                    // if (isvalid(p, v, visited, l, n, m)) {

bool isvalid(vector<int> &p, vector<int> &v, vector<vector<vector<bool>>> &visited, int l, int n, int m) {
    return p[0] + v[0] < l && p[0] + v[0] >= 0 && p[1] + v[1] < n && p[1] + v[1] >= 0 && p[2] + v[2] < m && p[2] + v[2] >= 0 
            && !visited[p[0] + v[0]][p[1] + v[1]][p[2] + v[2]];
}

int main() {
    vector<vector<int>> points = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    while (true) {
        int l, n, m;
        cin >> l >> n >> m;
        if (l == 0 && n == 0 && m == 0) break;
        char grid[l][n][m];
        vector<vector<vector<bool>>> visited(l, vector<vector<bool>>(n, vector<bool>(m)));
        // memset(visited, false, sizeof(false));
        vector<int> start (3);
        vector<int> end (3);
        for (int k = 0; k < l; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> grid[k][i][j];
                    if (grid[k][i][j] == 'S') {
                        start[0] = k;
                        start[1] = i;
                        start[2] = j;
                    }
                    if (grid[k][i][j] == 'E') {
                        end[0] = k;
                        end[1] = i;
                        end[2] = j;
                    }
                }
            }
        }
        queue<vector<int>> q;
        q.push(start);
        visited[start[0]][start[1]][start[2]] = true;
        int ans = 0;
        bool found = false;
        while (true) {
            int sz = q.size();
            if (sz == 0) break;
            while (sz--) {
                auto p = q.front();
                q.pop();
                if (p == end) {
                    found = true;
                    break;
                }
                if (grid[p[0]][p[1]][p[2]] == '#') continue;
                for (auto v: points) {
                    if (isvalid(p, v, visited, l, n, m)) {
                        q.push({p[0] + v[0], p[1] + v[1], p[2] + v[2]});
                        visited[p[0] + v[0]][p[1] + v[1]][p[2] + v[2]] = true;
                    }
                } 

            }
            if (found) break;
            ans++;
        }
        if (found) {
            cout << "Escaped in " << ans << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
        // # is rocks
        // . is empty
        // S is start
        // E is exit

    }
    return 0;
}