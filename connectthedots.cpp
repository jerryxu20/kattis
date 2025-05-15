#include <bits/stdc++.h>
using namespace std;

vector<string> grid;

void solve() {
    int n = grid.size();
    int m = grid[0].size();

    auto id = [] (char c) {
        if ('0' <= c && c <= '9') {
            return c - '0';
        }
        if ('a' <= c && c <= 'z') {
            return c - 'a' + 10;
        }
        if ('A' <= c && c <= 'Z') return c - 'A' + 36;
        return -1;
    };

    vector<pair<int, int>> at(100, {-1, -1});
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = id(grid[i][j]);
            if (x != -1) at[x] = {i, j};
        }
    }

    for (int k = 1; k < 100; k++) {
        if (at[k] == pair<int, int>(-1, -1)) break;

        auto [mn_i, mx_i] = minmax({at[k].first, at[k - 1].first});
        auto [mn_j, mx_j] = minmax({at[k].second, at[k - 1].second});

        for (int i = mn_i; i <= mx_i; i++) {
            if (grid[i][mn_j] == '.') {
                grid[i][mn_j] = '|';
            } else if (grid[i][mn_j] == '-') {
                grid[i][mn_j] = '+';
            }
        }
        for (int j = mn_j; j <= mx_j; j++) {
            if (grid[mn_i][j] == '.') {
                grid[mn_i][j] = '-';
            } else if (grid[mn_i][j] == '|') {
                grid[mn_i][j] = '+';
            }
        }
    }

    for (auto &s: grid) {
        cout << s << endl;
    }
    cout << endl;
    

    
    

}

int main() {
    string s;
    while(getline(cin, s)) {
        if (s == "") {
            solve();
            grid.clear();
        } else {
            grid.push_back(s);
        }
    }

    solve();
}