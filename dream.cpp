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
    int n, x;
    char c;
    string e;
    cin >> n;
    int time = 0;
    map<string, int> event;
    vector<string> timeline;
    while(n--) {
        cin >> c;
        if (c == 'E') {
            cin >> e;
            if (sz(timeline) <= time) timeline.push_back("");
            timeline[time] = e;
            event[e] = time++;
        } else if (c == 'D') {
            cin >> x;
            time -= x;
        } else {
            cin >> x;
            bool error = false;
            int mn = time;
            vector<string> check;
            for (int i = 0; i < x; i++) {
                cin >> e;
                if (e[0] == '!') {
                    e = e.substr(1);
                    if (!event.count(e) || event[e] >= time || timeline[event[e]] != e) continue;
                    mn = min(mn, event[e]);
                } else {
                    check.pb(e);
                }
            }
            for (auto &s: check) {
                if (!event.count(s) || event[s] >= mn || timeline[event[s]] != s) {
                    error = true;
                    break;
                }
            }
            if (error) {
                cout << "Plot Error\n";
                continue;
            }
            int rewind = time - mn;
            if (rewind == 0) cout << "Yes\n";
            else cout << rewind << " " << "Just a Dream\n";
        }
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