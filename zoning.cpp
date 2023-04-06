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

int main() {
    int n; 
    string s;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    int rem = 0;
    queue<pii> q;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j] - '0';
            if (grid[i][j] == 3) {
                q.push({i, j});
                grid[i][j] = 0;
            }
            if (grid[i][j] == 1) {
                rem++;
            }
        }
    }
    // for (auto &row: grid) {
    //     for (auto &cell: row) {
    //         cout << cell << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<int>> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int d = 0;
    while(sz(q)) {
        if (rem == 0) break;
        int z = sz(q);
        while(z--) {
            auto [i, j] = q.front();
            q.pop();
            // cout << "rem " << rem << endl; 
            for (auto &d: delta) {
                int ii = i + d[0];
                int jj = j + d[1];
                if (ii < 0 || jj < 0 || ii >= n || jj >= n) continue;
                if (grid[ii][jj] == 0) continue;
                if (grid[ii][jj] == 1) rem--;
                grid[ii][jj] = 0;
                q.push({ii, jj});
            }
        }
        // cout << endl;
        // for (auto &row: grid) {
            // for (auto &cell: row) {
                // cout << cell << " ";
            // }
            // cout << endl;
        // }
        d++;
        
    }
    cout << d << endl;
    return 0;
}