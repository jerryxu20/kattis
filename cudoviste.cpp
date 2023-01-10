#include <bits/stdc++.h>
using namespace std;

int dfs;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> ans(5);
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<pair<int, int>> box = {{0, 0}, {1, 1}, {1, 0}, {0, 1}};
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (grid[i][j] != '#') {
                int car = 0;
                for (auto p: box) {
                    if (grid[i + p.first][j + p.second] == '#') {
                        car = -1;
                        break;
                    }
                    if (grid[i + p.first][j + p.second] == 'X') {
                        car++;
                    }
                }
                if(car >= 0) {
                    ans[car]++;
                }
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}