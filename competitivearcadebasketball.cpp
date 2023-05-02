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
    int n, p, q, a;
    cin >> n >> p >> q;
    string s;
    while(n--) cin >> s;
    map<string, int> score;
    vector<string> winners;
    while(q--) {
        cin >> s >> a;
        score[s] += a;
        if (score[s] >= p) {
            winners.pb(s);
        }
    }
    score.clear();
    if (sz(winners) == 0) {
        cout << "No winner!\n";
        return 0; 
    }
    for (auto &w: winners) {
        if (score.count(w)) continue;
        score[w];
        cout << w << " wins!\n";
    }

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