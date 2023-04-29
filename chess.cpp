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

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int tcase) {
    char x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    int i = x - 'A';
    int j = y - '1';
    j = 7 - j;
    int ii = xx - 'A';
    int jj = yy - '1';
    jj = 7 - jj;
    bool m = (i % 2) == (j % 2);
    bool mm = (ii % 2) == (jj % 2);
    if (m != mm) {
        cout << "Impossible\n";
        return 0;
    }

    if (i == ii && j == jj) {
        cout << 0 << " " << x << " " << y << endl;
        return 0;
    }
    set<pii> target;
    for (int a = ii, b = jj; a >= 0 && a < 8 && b >= 0 && b < 8; a++, b++) {
        target.insert(mp(a, b));
    }
    for (int a = ii, b = jj; a >= 0 && a < 8 && b >= 0 && b < 8; a--, b--) {
        target.insert(mp(a, b));
    }
    for (int a = ii, b = jj; a >= 0 && a < 8 && b >= 0 && b < 8; a--, b++) {
        target.insert(mp(a, b));
    }
    for (int a = ii, b = jj; a >= 0 && a < 8 && b >= 0 && b < 8; a++, b--) {
        target.insert(mp(a, b));
    }

    if (target.count(mp(i, j))) {
        cout << 1 << " " << x << " " << y << " " << xx << " " << yy << endl;
        return 0;
    }
    pii mid;
    for (int a = i, b = j; a >= 0 && a < 8 && b >= 0 && b < 8; a++, b++) {
        if (target.count(mp(a, b))) {
            mid = mp(a, b);
            break;
        }
    }
    for (int a = i, b = j; a >= 0 && a < 8 && b >= 0 && b < 8; a--, b--) {
        if (target.count(mp(a, b))) {
            mid = mp(a, b);
            break;
        }
    }
    for (int a = i, b = j; a >= 0 && a < 8 && b >= 0 && b < 8; a--, b++) {
        if (target.count(mp(a, b))) {
            mid = mp(a, b);
            break;
        }
    }
    for (int a = i, b = j; a >= 0 && a < 8 && b >= 0 && b < 8; a++, b--) {
        if (target.count(mp(a, b))) {
            mid = mp(a, b);
            break;
        }
    }
    cout << 2 << " " << x << " " << y << " " << char(mid.first + (int)'A') << " " << char(7 - mid.second + (int)'1') << " " << xx << " " << yy << endl;
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