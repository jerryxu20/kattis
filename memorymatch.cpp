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
    int n, k, a, b;
    string s, t;
    cin >> n >> k;
    map<string, set<int>> cards;
    while(k--) {
        cin >> a >> b >> s >> t;
        if (s == t) {
            cards.erase(s);
            n -= 2;
            continue;
        }
        cards[s].insert(a);
        cards[t].insert(b);
    }
    int ans = 0;
    int seen = 0;
    for (auto &[face, position]: cards) {
        assert(sz(position) != 0);
        if (sz(position) == 2) {
            position.clear();
            n -= 2;
            ans++;
        } else {
            seen++;
        }
    }
    int facedown = n - seen;
    if (facedown <= seen) ans += n/2;
    if (facedown == 2 && seen == 0) ans++;

    cout << ans << endl;
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