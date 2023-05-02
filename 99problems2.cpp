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
    int n, q, a, b;
    cin >> n >> q;
    vi diff(n);
    for (auto &d: diff) cin >> d;
    multiset<int> prob(all(diff));
    while(q--) {
        cin >> a >> b;
        // 1: remove all harder than b
        // 2: remove all easier than b
        if (a == 1) {
            auto it = prob.upper_bound(b);
            if (it == prob.end()) {
                cout << - 1 << "\n";
            } else {
                cout << *it << "\n";
                prob.erase(it);
            }
        } else if (a == 2) {
            auto it = prob.upper_bound(b);
            if (it == prob.begin()) {
                cout << -1 << "\n";
            } else {
                it--;
                cout << *it << "\n";
                prob.erase(it);
            }
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