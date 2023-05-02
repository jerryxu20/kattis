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
int n, m;
vs grid;
vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    if (grid[i][j] != '.' && grid[i][j] != ' ') return 0;
    int cnt = grid[i][j] == '.';
    grid[i][j] = 'X';
    for (auto d: delta4) {
        int ii = d[0] + i;
        int jj = d[1] + j;
        cnt += dfs(ii, jj);
    }
    return cnt;
}

string scrap;
int solve(int tcase) {
    cin >> n >> m;
    getline(cin, scrap);
    int ans = 0;
    grid.resize(n);
    for (auto &s: grid) getline(cin, s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] <= 'W' && grid[i][j] >= 'A') {
                grid[i][j] = ' ';
                if (dfs(i, j)) ans++;
            }
        }
    }
    int cnt = 0;
    for (auto &row: grid) {
        cnt += count(all(row), '.');
    }
    cout << ans << " " << cnt << endl;
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}