#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair


int solve() {
    int nx, ny;
    double w;
    while (true) {
        cin >> nx >> ny >> w;
        if (nx == 0 && ny == 0) break;
        vector<double> lengths(nx);
        vector<double> widths(ny);
        for (auto &l: lengths) {
            cin >> l;
        }
        for (auto &l: widths) {
            cin >> l;
        }
        sort(all(lengths));
        sort(all(widths));
        bool valid = true;
        double mx = 0;
        for (auto &x: widths) {
            double lower = x - w/2;
            double upper = x + w/2;
            if (lower <= mx) {
                mx = upper;
            } else {
                valid = false;
                break;
            }
        }
        if (mx < 100) {
            valid = false;
        }
        mx = 0;
        for (auto &x: lengths) {
            double lower = x - w/2;
            double upper = x + w/2;
            if (lower <= mx) {
                mx = upper;
            } else {
                valid = false;
                break;
            }
        }
        if (mx < 75) valid = false;
        if (valid == false) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }
    return 0;
    
}

int main() {
    int tcase = 1;
    // cin >> tcase;
    for (int i = 1; i <= tcase; i++) {
        // cout << "Case #" << i << " : ";
        solve();
    }
    return 0;
}