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
int h, n, m;
vii delta = {{-1, -1}, {-1, 1}, {0, 2}, {1, -1}, {1, 1}, {0, -2}};

int dfs(int i, int j, vs &grid) {
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    if (grid[i][j] != '.') return 0;
    grid[i][j] = '#';
    int ans = 1;
    for (auto &d: delta) {
        int ii = i + d[0];
        int jj = j + d[1];
        ans += dfs(ii, jj, grid);
    }
    return ans;
}


int solve(int tcase) {
    cin >> h >> n >> m;
    m *= 2;
    string s;
    getline(cin, s);
    vs grid(n);
    for (auto &line: grid) {
        getline(cin, line);
        if (sz(line) < m) line += ' ';
    }
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') pq.push(dfs(i,j,grid));
        }
    }
    int ans = 0;
    while(h > 0) {
        ans++;
        h -= pq.top();
        pq.pop();
    }
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