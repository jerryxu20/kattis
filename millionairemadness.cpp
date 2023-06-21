#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair

vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
vii grid;
bool check(int mid) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m));
    q.push({0, 0});
    visited[0][0] = true;
    while(true) {
        int s = sz(q);
        if (s == 0) break;
        while(s--) {
            auto [i, j] = q.front();
            q.pop();
            for (auto &d: delta4) {
                int ii = i + d[0];
                int jj = j + d[1];
                if (ii < 0 || jj < 0 || ii >= n || jj >= m || visited[ii][jj] || grid[ii][jj] - grid[i][j] > mid) continue;
                visited[ii][jj] = true;
                q.push({ii, jj});
            }

        }
    }
    return visited.back().back();
}

int solve(int tt) {
    cin >> n >> m;
    int low = 0;
    int high = 0;
    grid.assign(n, vi(m));
    for(auto &row: grid) {
        for (auto &cell: row) {
            cin >> cell;
            high = max(high, cell);
        }
    }
    int ans = high;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    t++;
    return 0;
}