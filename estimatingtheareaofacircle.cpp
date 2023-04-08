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
    double r;
    int n, m;
    while(cin >> r >> n >> m) {
        if (n == 0) break;
        double d = 2 * r;
        double actual = M_PI * r * r;
        double exp = (double) m / n * d * d;
        cout << setprecision(7) << fixed << actual << " " << exp << endl;
    }
    return 0;
}