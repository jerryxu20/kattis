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

int solve(int tcase) {
    int s, a, b;
    string hit;
    cin >> s;
    set<pii> targs;
    rep(i,0,4) {
        do {
            s = s + s/13 + 15;
            a = (s % 100) / 10;
            b = (s % 10);
        } while (targs.count(mp(a, b)));
        targs.insert(mp(a, b));
    }
    int moves = 0;
    while(cin >> hit) {
        moves++;
        a = hit[0] - '0';
        b = hit[1] - '0';
        if (targs.count(mp(a,b))) {
            targs.erase(mp(a, b));
            cout << "You hit a wumpus!\n";
        }
        if (sz(targs)) {
            int ans = 10000;
            for (auto &[x, y]: targs) {
                ans = min(ans, abs(x - a) + abs(y - b));
            }
            cout << ans << endl;
        }
    }
    cout << "Your score is " << moves << " moves.\n";


    tcase++;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
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