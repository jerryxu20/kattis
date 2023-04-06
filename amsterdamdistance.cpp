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
    int m, n;
    double r, ring;
    cin >> m >> n >> r;
    // m is slices of pie
    // n is number of rings
    // r is radius
    ring = r / n;
    pii a;
    pii b;
    cin >> a.first >> a.second >> b.first >> b.second;
    double ans = 10e9;
    for (int road = 0; road <= max(a.second, b.second); road++) {
        double radial = (abs(road - a.second) + abs(road - b.second)) * ring;
        // pi r
        double wrap = M_PI * ring * road * abs(a.first - b.first) / m;
        ans = min(ans, radial + wrap);
    }
    cout << setprecision(20) << fixed << ans << endl;
    return 0;
}