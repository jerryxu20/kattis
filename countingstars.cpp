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

#define pb push_back
#define mp make_pair

int n, m;
vector<string> sky;
vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j) {
    if (sky[i][j] != '-') return;
    sky[i][j] = ' ';
    for (auto &d: delta4) {
        int ii = d[0] + i;
        int jj = d[1] + j;
        if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
        dfs(ii, jj);
    }
    return;
}

int solve(int tcase) {
    while(cin >> n) {
        cin >> m;
        sky.resize(n);
        for (auto &row: sky) cin >> row;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (sky[i][j] != '-') continue;
                dfs(i, j);
                ans ++;
            }
        }
        cout << "Case " << tcase++ << ": " << ans << endl; 
    }


    return 0;
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
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