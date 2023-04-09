#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int tcase) {
    int w, h, n;
    cin >> w >> h >> n;
    vector<string> grid1(h);
    vector<string> grid2(h);
    int ship1 = 0, ship2 = 0;
    for (auto &row: grid1) {
        cin >> row;
        ship1 += count(all(row), '#');
    }
    for (auto &row: grid2) {
        cin >> row;
        ship2 += count(all(row), '#');
    }
    vector<pii> moves(n);
    for (auto &[xx, yy]: moves) {
        cin >> xx >> yy;
        yy = h - 1 - yy;
    }
    int idx = 0;
    while (idx < sz(moves)) {
        //first player
        bool hit = true;
        do {
            auto &[j, i] = moves[idx++];
            if (grid2[i][j] == '#') {
                grid2[i][j] = '_';
                ship2--;
            } else {
                hit = false;
            }
        } while (hit && idx < sz(moves) && ship2 > 0);
        //second player
        // if (idx >= sz(moves)) break;
        hit = true;
        do {
            auto &[j, i] = moves[idx++];
            if (grid1[i][j] == '#') {
                grid1[i][j] = '_';
                ship1--;
            } else {
                hit = false;
            }
        } while (hit && idx < sz(moves) && ship1 > 0);
        if (ship1 == 0 || ship2 == 0) break;
    }
    
    if ((ship1 == 0 && ship2 == 0) || (ship1 > 0 && ship2 > 0)) {
        cout << "draw\n";
    } else if (ship1 == 0) {
        cout << "player two wins\n";
    } else if (ship2 == 0) {
        cout << "player one wins\n";
    }
    tcase++;
    return 0;
}

int main() {
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