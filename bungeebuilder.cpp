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
    int n;
    cin >> n;
    vi mountains(n);
    for (auto &h: mountains) cin >> h;
    int ans = 0;
    vector<pii> stack;
    for (auto &h: mountains) {
        int between = h;
        while (sz(stack) && stack.back().first < h) {
            between = min(between, stack.back().second);
            stack.pop_back();
        }
        if (sz(stack)) {
            ans = max(ans, h - between);
        }
        stack.pb(mp(h, between));
    }
    stack.clear();
    reverse(all(mountains));
    for (auto &h: mountains) {
        int between = h;
        while (sz(stack) && stack.back().first < h) {
            between = min(between, stack.back().second);
            stack.pop_back();
        }
        if (sz(stack)) {
            ans = max(ans, h - between);
        }
        stack.pb(mp(h, between));
    }
    cout << ans << endl;

    tcase++;
    return 0;
}

int main() {
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