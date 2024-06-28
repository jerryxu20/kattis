#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> ti;

int grid[500][500];
int dis[500][500];


vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            grid[i][j] *= -1;
        }
    }
    int a, b; cin >> a >> b;
    a--; b--;

    priority_queue<ti> pq;

    pq.push({grid[a][b], a, b});
    dis[a][b] = grid[a][b];

    long long ans = 0;
    
    

    while(pq.size()) {
        auto [d, i, j] = pq.top();
        pq.pop();
        if (dis[i][j] != d) continue;

        ans += d;

        for (auto &[x, y]: delta) {
            int ii = i + x;
            int jj = j + y;

            if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
            if (grid[ii][jj] <= 0) continue;

            int cand = min(d, grid[ii][jj]);

            if (cand > dis[ii][jj]) {
                dis[ii][jj] = cand;
                pq.push({cand, ii, jj});
            }
        }
    }

    cout << ans << endl;


}