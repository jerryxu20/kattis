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

set<pair<char, char>> w = {{'R', 'S'}, {'S', 'P'}, {'P', 'R'}};
bool wins(char a, char b) {
    return w.count(mp(a,b));
}

int solve(int tcase) {
    int n, m, t;
    cin >> n >> m >> t;
    vector<string> grid(n);
    vector<string> copy(n);
    for (auto &row: grid) cin >> row;
    while(t--) {
        copy = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto &d: delta4) {
                    int ii = i + d[0];
                    int jj = j + d[1];
                    if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                    if (wins(grid[i][j], grid[ii][jj])) copy[ii][jj] = grid[i][j];
                }
            }
        }
        grid = copy;
    }
    for (auto &row: grid) {
        cout << row << endl;
    }
    cout << endl;
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