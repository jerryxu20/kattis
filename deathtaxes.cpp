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
    string c;
    ll x, y;
    ll total = 0;
    ll value = 0;
    ll n = 0;
    while(cin >> c) {
        if (c == "buy") {
            cin >> x >> y;
            n += x;
            total += x;
            value += x * y;
        } else if (c == "sell") {
            cin >> x >> y;
            n -= x;
        } else if (c == "split") {
            cin >> x;
            n *= x;
            total *= x;
        } else if (c == "merge") {
            cin >> x;
            n /= x;
            value *= x;
        } else {
            cin >> x;
            if (total == 0 || n == 0) {
                cout << 0 << endl;
                return 0;
            }
            double prof = max((x - (double)value/total)* 0.3, 0.0);
            cout << fixed << setprecision(10) << n * (x - prof) << endl;
            return 0;
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