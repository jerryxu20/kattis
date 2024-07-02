#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
int grid[100][100];
int main() {
    int T; cin >> T;
    while(T--) {
        int m, n; cin >> m >> n;
        vector<pi> X, Y;
        int sm = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j]) {
                    X.push_back({i, grid[i][j]});
                    Y.push_back({j, grid[i][j]});
                }
                sm += grid[i][j];
            }
        }

        int targ = sm/2;
        int seen = 0;
        int x = 0;
        sort(X.begin(), X.end());

        for (auto &[xx, cnt]: X) {
            seen += cnt;
            x = xx;
            if (seen > targ) break;
        }
        
        sort(Y.begin(), Y.end());
        int y = 0;
        seen = 0;

        for (auto &[yy, cnt]: Y) {
            seen += cnt;
            y = yy;
            if (seen > targ) break;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += grid[i][j] * (abs(i - x) + abs(j - y));
            }
        }

        cout << ans << " blocks\n";
    }
}