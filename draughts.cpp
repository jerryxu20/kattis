#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 10;

string grid[MAXN];
vector<pi> delta = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int dfs(int i, int j) {
    int ans = 0;
    for (auto &[a, b]: delta) {
        int ii = i + a;
        int jj = j + b;

        int iii = ii + a;
        int jjj = jj + b;
        if (iii < 0 || jjj < 0 || iii >= MAXN || jjj >= MAXN) continue;
        if (grid[ii][jj] != 'B' || grid[iii][jjj] != '.') continue;
        
        grid[ii][jj] = '.';
        ans = max(ans, 1 + dfs(iii, jjj));
        grid[ii][jj] = 'B';
    }
    return ans;
}

int solve() {
    for (int i = 0; i < MAXN; i++) {
        cin >> grid[i];
    }

    int ans = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (grid[i][j] == '#') grid[i][j] = '.';
        }
    }
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (grid[i][j] == 'W') {
                grid[i][j] = '.';
                ans = max(ans, dfs(i, j));
                grid[i][j] = 'W';
            }
        }
    }
    cout << ans << endl;
    return 0;
}


int main() {
    int t; cin >> t;
    while(t--) solve();
}