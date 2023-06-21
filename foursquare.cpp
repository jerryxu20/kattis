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
bool check(pii &a) {
    return a.first == a.second;
}
vector<pii> merge(pii &a, pii&b) {
    set<pii> rects;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a.first == b.first) {
                int s1 = a.first;
                int s2 = a.second + b.second;
                rects.insert(mp(min(s1, s2), max(s1, s2)));
            }
            swap(b.first, b.second);
        }
        swap(a.first, a.second);
    }
    vector<pii> ans (all(rects));
    return ans;
}

bool dfs(vector<pii> &rects, int level) {
    if (level == 0) {
        for (auto &r: rects) {
            if (check(r)) return true;
        }
        return false;
    }

    int n = rects.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vpii block = merge(rects[i], rects[j]);
            vpii rem;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                rem.pb(rects[k]);
            }
            for (auto &b: block) {
                rem.pb(b);
                if (dfs(rem, level - 1)) return true;
                rem.pop_back();
            }
        }
    }
    return false;
}


int solve(int tt) {
    vector<pii> rects(4);

    for (auto &[a, b]: rects) cin >> a >> b;

    if (dfs(rects, 3)) cout << 1 << endl;
    else cout << 0 << endl;
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