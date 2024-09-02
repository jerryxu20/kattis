#include <bits/stdc++.h>
using namespace std;

// 4:55
// 5:09

const int MAXN = 1000;
string grid[MAXN];

typedef pair<int, int> pi;

int seen[MAXN][MAXN];
int ans[MAXN][MAXN];
vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

pair <int, int> dir(char &c) {
    if (c == 'N') return {-1, 0};
    if (c == 'S') return {1, 0};
    if (c == 'W') return {0, -1};
    if (c == 'E') return {0, 1};
    assert(false);
    return {0, 0};
}
int main() {
    int n, m; cin >> m >> n;

    for (int i = 0; i < n; i++) cin >> grid[i];
    string S; cin >> S;

    pair<int, int> s;
    memset(seen, -1, sizeof(seen));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (grid[i][j] == 'S') {
            s = {i, j};
            break;
        }
    }

    queue<pair<int, int>> q;
    q.push(s);
    seen[s.first][s.second] = 0;

    auto valid = [&] (int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        return grid[i][j] != '#';
    };

    while(true) {
        int z = q.size();
        if (z == 0) break;
        while(z--) {
            auto [i, j] = q.front();
            q.pop();

            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                if (valid(ii, jj) && seen[ii][jj] == -1) {
                    seen[ii][jj] = seen[i][j] + 1;
                    q.push({ii, jj});
                }
            }
        }
    }


    memset(ans, -1, sizeof(ans));
    q.push(s);
    ans[s.first][s.second] = 0;

    while(true) {
        int z = q.size();
        if (z == 0) break;
        while(z--) {
            auto [i, j] = q.front();
            q.pop();
            int idx = ans[i][j];
            if (idx == (int)S.size()) continue;

            for (auto &[a, b]: delta) {
                if (pi(a, b) == dir(S[idx])) continue;

                int ii = i + a;
                int jj = j + b;
                if (valid(ii, jj) && ans[ii][jj] == -1 && seen[ii][jj] == ans[i][j] + 1) {
                    ans[ii][jj] = ans[i][j] + 1;
                    q.push({ii, jj});
                }
            }
        }
    } 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (ans[i][j] == (int)S.size()) {
            grid[i][j] = '!';
        }
    }

    for (int i = 0; i < n; i++) {
        cout << grid[i] << endl;
    }   
}