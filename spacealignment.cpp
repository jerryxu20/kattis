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

bool matches(char a, char b) {
    return a == '{' && b == '}';
}

int solve(int tt) {
    int n;
    string s;
    cin >> n;
    vii check;
    vector<vector<int>> stack;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int a = count(all(s), 's');
        int b = count(all(s), 't');
        if (sz(stack) && matches((char)stack.back()[0], s.back())) {
            check.pb({stack.back()[1], stack.back()[2], a, b});
            stack.pop_back();
        } else {
            stack.pb({(int)s.back(), a, b});
        }
    }
    for (int i = 1; i <= 1000; i++) {
        bool valid = true;
        for (auto &c: check) {
            if (c[0] + c[1] * i != c[2] + c[3] * i) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;


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