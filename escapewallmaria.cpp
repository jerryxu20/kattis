#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int t, n, m;

bool ob(int i, int j) {
    return i < 0 || j < 0 || i >= n || j >= m;
}

bool valid(int i, int j, char c, vector<int> &d) {
    if (c == '1') return false;
    if (ob(i, j)) return false;
    if (c == '0') return true;
    switch (c) {
        case 'U':
            return d[0]  == 1;
        case 'D':
            return d[0] == -1;
        case 'L':
            return d[1] == 1;
        case 'R':
            return d[1] == -1;
    }
    return false;
}

bool wall(int i, int j) {
    return i == 0 || i == n - 1 || j == 0 || j == m - 1;
}

int main() {
    cin >> t >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                q.push(mp(i, j));
                grid[i][j] = '1';
            }
        }
    }
    vector<vector<int>> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int time = 0;
    while (time <= t) {
        int sz = sz(q);
        if (sz == 0) break;
        while (sz--) {
            auto [i, j] = q.front();
            // cout << i << " " << j << endl;
            q.pop();
            if (wall(i, j)) {
                cout << time << endl;
                return 0;
            }        
            for (auto &d: delta) {
                int ii = i + d[0];
                int jj = j + d[1];
                if (ob(ii, jj)) continue;
                if (!valid(ii, jj, grid[ii][jj], d)) continue;
                q.push(mp(ii, jj));
                grid[ii][jj] = '1';
            }
        }
        time++;
    }
    cout << "NOT POSSIBLE" << endl;
    return 0;
}