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

vii delta4 = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
vii delta2 = {{-1, 0}, {-1, 1}};
// int ans = INT_MAX;
int n, m;
int ans = INT_MAX;

vector<char> check_square(vs &grid, int i, int j) {
    vector<char> a;
    if (i != 0) {
        int valid = 0;
        for (auto &d: delta2) {
            int ii = i + d[0];
            int jj = j + d[1];
            if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
            if (grid[ii][jj] == 'k') valid++;
       }
       if (valid == 0) return a;
    }

    for (auto &d: delta4) {
        int ii = i + d[0];
        int jj = j + d[1];
        if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
        a.push_back(grid[ii][jj]);
    }
    return a;
}

void f(vs &grid, int idx, int moves) {
    if (idx >= n*m) {
        ans = min(ans, moves);
        return;
    }
    if (moves >= ans) return;
    // make a square here
    int i = idx/m;
    int j = idx % m; 
    if (grid[i][j] == 'k') {
        f(grid, idx + 1, moves);
        return;
    }    
    vector<char> square = check_square(grid, i, j);
    if (sz(square) == 4) {
        for (auto &d: delta4) {
            int ii = i + d[0];
            int jj = j + d[1];
            grid[ii][jj] = 'k';
        }
        f(grid, idx, moves + 1);
        for (int k = 0; k < 4; k++) {
            int ii = i + delta4[k][0];
            int jj = j + delta4[k][1];
            grid[ii][jj] = square[k];
        }
    }
    if (grid[i][j] != '#') f(grid, idx + 1, moves);

    return;
}



int solve(int tcase) {
    cin >> n >> m;
    vs grid(n);
    for (auto &row: grid) cin >> row;
    reverse(all(grid));
    f(grid, 0, 0);
    cout << ans << endl;
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