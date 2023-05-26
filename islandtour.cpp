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
int n;
int arrives(vector<int> &psum, int s, int t) {
    if (t < s) t += n;
    return psum[t] - psum[s];
}

bool intersects(pii&a, pii&b) {
    return !(a.second <= b.first || b.second <= a.first);
}

int solve(int tcase) {
    cin >> n;
    vi travel(n);
    vii times(3, vi(n));
    for (auto &x: travel) cin >> x;
    for (auto &row: times)
        for (auto &x: row) cin >> x;
    vii prefixtimes(3, vi(2*n));
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 2*n; j++) {
            int prev = (j - 1 + n) % n;
            prefixtimes[i][j] = prefixtimes[i][j - 1] + times[i][prev] + travel[prev];
        }
    }
    viii tours(3, vii(n, vi(n)));
    vector<vector<vector<bool>>> conflict(3, vector<vector<bool>>(n, vector<bool>(n)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int att = 0; att < n; att++) {
                pii r1 = mp(arrives(prefixtimes[0], i, att), times[0][att]);
                pii r2 = mp(arrives(prefixtimes[1], j, att), times[1][att]);
                r1.second += r1.first;
                r2.second += r2.first;
                conflict[0][i][j] = intersects(r1, r2);
                if (conflict[0][i][j]) break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int att = 0; att < n; att++) {
                pii r1 = mp(arrives(prefixtimes[0], i, att), times[0][att]);
                pii r3 = mp(arrives(prefixtimes[2], k, att), times[2][att]);
                r1.second += r1.first;
                r3.second += r3.first;
                conflict[1][i][k] = intersects(r1, r3);
                if (conflict[1][i][k]) break;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            for (int att = 0; att < n; att++) {
                pii r2 = mp(arrives(prefixtimes[1], j, att), times[1][att]);
                pii r3 = mp(arrives(prefixtimes[2], k, att), times[2][att]);
                r2.second += r2.first;
                r3.second += r3.first;
                conflict[2][j][k] = intersects(r2, r3);
                if (conflict[2][j][k]) break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (conflict[0][i][j] || conflict[1][i][k] || conflict[2][j][k]) continue;
                cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                return 0;
            }
        }
    }
    cout << "impossible\n";
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