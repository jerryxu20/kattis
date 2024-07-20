#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50;
int grid[MAXN][MAXN];
int seen[MAXN][MAXN];
int id = 0;

vector<pair<int, int>> delta = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
typedef pair<int, int> pi;

int n, m;
int dfs(int i, int j, int pi = -1, int pj = -1) {
    seen[i][j] = id;
    int res = 0;
    for (int k = 0; k < 4; k++) {
        auto [a, b] = delta[k];
        int ii = i + a;
        int jj = j + b;
        if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
        if (grid[i][j] & (1 << k)) continue;
        if (ii == pi && jj == pj) continue;
        if (seen[ii][jj] == id) {
            res = 1;
            continue;
        }
        res |= dfs(ii, jj, i, j);
    }
    return res;
}

int solve() {
    cin >> n >> m;
    if (n == 0 && m == 0) return 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c <= '9') {
                grid[i][j] = c - '0';
            } else {
                grid[i][j] = c - 'A' + 10;
            }
        }
    }
    vector<pi> holes;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            for (int k = 0; k < 4; k++) {
                auto [a, b] = delta[k];
                int ii = i + a;
                int jj = j + b;

                if (ii < 0 || jj < 0 || ii >= n || jj >= m) {
                    if ((grid[i][j] & (1 << k)) == 0) {
                        holes.push_back({i, j});
                    }
                }
            }
        }
    }
    id++;
    int mult = dfs(holes[0].first, holes[0].second);

    if (seen[holes[1].first][holes[1].second] != id) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (seen[i][j] != id) {
            cout << "UNREACHABLE CELL\n";
            return 0;
        }
    }

    if (mult) {
        cout << "MULTIPLE PATHS\n";
        return 0;
    }

    cout << "MAZE OK\n";
    return 0;
}


int main() {
    while(solve() == 0) {};
}