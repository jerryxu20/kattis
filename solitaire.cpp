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
int n = 5;
int m = 9;
pii ans;
void backtrack(vs &grid, int cnt, int moves) {
    ans = min(mp(cnt, moves), ans);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 'o') continue;
            for (auto &d: delta4) {
                int ii = i + d[0];
                int jj = j + d[1];
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                if (grid[ii][jj] != 'o') continue;
                int iii = i + d[0] * 2;
                int jjj = j + d[1] * 2;
                if (iii < 0 || jjj < 0 || iii >= n || jjj >= m) continue;
                if (grid[iii][jjj] != '.') continue;
                grid[i][j] = '.';
                grid[ii][jj] = '.';
                grid[iii][jjj] = 'o';
                backtrack(grid, cnt - 1, moves + 1);
                grid[i][j] = 'o';
                grid[ii][jj] = 'o';
                grid[iii][jjj] = '.';
            }
        }
    }
    return;
}
int solve(int tcase) {
    vs grid(5);
    for (auto &s: grid) cin >> s;
    int pegs = 0;
    for (auto &s: grid) pegs += count(all(s), 'o');
    ans = mp(INT_MAX, INT_MAX);
    backtrack(grid, pegs, 0);
    cout << ans.first << " " << ans.second << endl;
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}