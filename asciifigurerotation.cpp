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

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string scrap;
int solve(int tcase) {
    int n;
    cin >> n;
    getline(cin, scrap);
    if (n == 0) return 1;
    if (tcase > 1) cout << endl;
    int m = 0;
    vs art(n);
    for (auto &a: art) {
        getline(cin, a);
        m = max(m, sz(a));
    }
    for (auto &a: art) {
        a.resize(m, ' ');
    }
    reverse(all(art));
    vs rot(m, string(n, ' '));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rot[j][i] = art[i][j];
        }
    }
    // for (auto &row: rot) {
    //     cout << row << endl;
    // }
    // return 0;
    for (auto &row: rot) {
        replace(all(row), '|', ';');
        replace(all(row), '-', '|');
        replace(all(row), ';', '-');
        while(sz(row) && row.back() == ' ') row.pop_back();
        cout << row << endl;
    }
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    // for (int i = 1; i <= testcase; i++) {
    //     solve(i);
    // }
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    testcase++;
    return 0;
}