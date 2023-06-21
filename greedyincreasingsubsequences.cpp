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

int solve(int tt) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &x: nums) cin >> x;
    set<pair<int, int>> st;
    // st.insert(mp(0, 0));
    // auto it = st.upper_bound(mp(0, 0));
    // if (it == st.end()) return 0;
    // cout << it->first << " " << it->second;
    int id = 0;
    vector<vi> ans(n);
    int idx;
    for (auto &x: nums) {
        auto it = st.upper_bound(mp(-x, INT_MAX));
        if (it == st.end()) {
            idx = id++;
        } else {
            idx = (it->second);
            st.erase(it);
        }
        st.insert(mp(-x, idx));
        ans[idx].pb(x);
    }
    while(sz(ans.back()) == 0) ans.pop_back();
    cout << sz(ans) << endl;
    for (auto &row: ans) {
        for (auto &num: row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    t++;
    return 0;
}