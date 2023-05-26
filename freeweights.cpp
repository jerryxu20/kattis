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
bool check(vii &weights, int mid) {
    for (auto &row: weights) {
        vi stack;
        for (auto &w: row) {
            if (w <= mid) continue;
            if (sz(stack) && stack.back() == w) {
                stack.pop_back();
                continue;
            }
            if (sz(stack) && stack.back() != w) return false;
            stack.pb(w);
        }
        if (sz(stack)) return false;
    }
    return true;
}

int solve(int tcase) {
    int n;
    cin >> n;
    vii weights(2, vi(n));
    for (auto &row: weights) {
        for (auto &w: row) cin >> w;
    }
    int low = 0;
    int high = max(*max_element(all(weights[0])), *max_element(all(weights[1])));
    int ans = high;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (check(weights, mid)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;

    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
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