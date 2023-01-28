#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    pii goat, bl, tr;
    cin >> goat.first >> goat.second >> bl.first >> bl.second >> tr.first >> tr.second;
    double ans = 100000;
    if (goat.first >= bl.first && goat.first <= tr.first) {
        ans = min({ans, (double)abs(goat.second - bl.second), (double)abs(goat.second - tr.second)});
    }
    if (goat.second >= bl.second && goat.second <= tr.second) {
        ans = min({ans, (double)abs(goat.first - bl.first), (double)abs(goat.first - tr.first)});
    }
    // from my point to each corner
    // bottom left
    double x = abs(goat.first - bl.first);
    double y = abs(goat.second - bl.second);
    ans = min(ans, sqrt(x * x + y * y));
    // bottom right
    x = abs(goat.first - tr.first);
    y = abs(goat.second - bl.second);
    ans = min(ans, sqrt(x * x + y * y));
    // top right
    x = abs(goat.first - tr.first);
    y = abs(goat.second - tr.second);
    ans = min(ans, sqrt(x * x + y * y));

    // top left
    x = abs(goat.first - bl.first);
    y = abs(goat.second - tr.second);
    ans = min(ans, sqrt(x * x + y * y));
    cout << setprecision(20) << ans << endl;
    return 0;
}