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
    int k, m, n, cnt;
    string s;
    cin >> k;
    if (k == 0) return 1;
    cin >> m;
    set<string> plan;
    while(k--) {
        cin >> s;
        plan.insert(s);
    }
    bool valid = true;
    while(m--) {
        cin >> n >> cnt;
        while(n--) {
            cin >> s;
            if (plan.count(s)) cnt--;
        }
        if (cnt > 0) valid = false;
    }
    if (valid) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    // for (int i = 1; i <= testcase; i++) {
    //     solve(i);
    // }
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    testcase++;
    return 0;
}