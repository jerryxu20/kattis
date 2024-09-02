#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> row(n), col(m);
    for (int &x: row) cin >> x;
    for (int &x: col) cin >> x;

    vector<int> idx1(n), idx2(m);
    iota(idx1.begin(), idx1.end(), 0);
    iota(idx2.begin(), idx2.end(), 0);

    sort(idx1.begin(), idx1.end(), [&] (auto &a, auto &b) {
        return row[a] < row[b];
    });

    sort(idx2.begin(), idx2.end(), [&] (auto &a, auto &b) {
        return col[a] < col[b];
    });


    int i = 0;
    int j = 0;

    vector<vector<int>> grid(n, vector<int>(m, -1));
    while(i < n && j < m) {
        if (row[idx1[i]] < col[idx2[j]]) {
            for (int jj = 0; jj < m; jj++) if (grid[idx1[i]][jj] == -1) {
                grid[idx1[i]][jj] = row[idx1[i]];
            }
            i++;
        } else {
            for (int ii = 0; ii < n; ii++) if (grid[ii][idx2[j]] == -1) {
                grid[ii][idx2[j]] = col[idx2[j]];
            }
            j++;
        }
    }

    while(i < n) {
        for (int jj = 0; jj < m; jj++) if (grid[idx1[i]][jj] == -1) {
            grid[idx1[i]][jj] = row[idx1[i]];
        }
        i++;
    }

    while(j < m) {
        for (int ii = 0; ii < n; ii++) if (grid[ii][idx2[j]] == -1) {
            grid[ii][idx2[j]] = col[idx2[j]];
        }
        j++;
    }

    

    
    vector<int> mxrow(n), mxcol(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mxrow[i] = max(mxrow[i], grid[i][j]);
            mxcol[j] = max(mxcol[j], grid[i][j]);
        }
    }

    if (mxrow == row && mxcol == col) {
        cout << "possible\n";
        return 0;
    }

    cout << "impossible\n";
}