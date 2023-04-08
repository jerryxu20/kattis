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
    int s;
    double a, b, m, n;
    while (cin >> a >> b >> s >> m >> n) {
        if (s == 0) break;
        double frac = (n * b) / (m * a);
        double angle = atan(frac) * 180 / M_PI;
        double factor = max(m, n);
        double side1 = m * a / factor;
        double side2 = n * b / factor;
        double distance = sqrt(side1 * side1 + side2 * side2) * factor;
        double speed = distance / s;
        cout << setprecision(2) << fixed << angle << " " << speed << endl;
    }
    return 0;
}