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
map<int, int> total;
int solve(int tcase) {
    int rank = 25;
    int stars = 0;
    int cur = 0;
    string s;
    cin >> s;
    for (char &c: s) {
        if (c == 'L') cur = 0;
        if (c == 'L' && rank <= 20 && rank >= 1)  stars--;
        if (stars == -1) {
            if (rank == 20) {
                stars = 0;
            } else {
                rank++;
                stars = total.lower_bound(rank)->second - 1;
            }
        }
        if (c == 'W') {
            stars++;
            cur++;
        }
        if (rank >= 6 && rank <= 25 && cur >= 3) stars++;
        if (stars > total.lower_bound(rank)->second) {
            stars = stars - total.lower_bound(rank)->second;
            rank--;
        }
        if (rank == 0) break;
    }
    if (rank == 0) {
        cout << "Legend\n";
    } else {
        cout << rank << endl;
    }
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    total[25] = 2;
    total[20] = 3;
    total[15] = 4;
    total[10] = 5;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}