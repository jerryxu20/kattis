#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
    int n, k, d, s;
    // total number of problems and solved so far
    cin >> n >> k;
    // diff of all, diff os solved
    cin >> d >> s;

    int total = d * n;
    int solved = k * s;
    double ans = (double) (total - solved) / (n - k);
    if (ans < 0 || ans > 100) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << setprecision(20) << fixed << ans << endl;
    return 0;
}