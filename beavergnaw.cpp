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
    int D, V;
    cin >> D >> V;
    if (D == 0 && V == 0) return 1;
    double total = (M_PI * (double)D * D * D / 8.0 - V / 2.0);
    // cout << "total" << total << endl;
    double d = (total - M_PI / 24.0 * D * D * D) / (M_PI * (1/8.0 - 1/24.0));
    d = cbrt(d);
    cout << setprecision(15) << fixed << d << endl;    
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