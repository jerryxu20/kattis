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
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int ans = 1;
        double mx = 0;
        for (int i = 1; i <= n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            double peak = 0.25 * b * b / a + c;
            if (peak > mx) {
                ans = i;
                mx = peak;
            }
        }
        cout << ans << endl;
    }
    return 0;
}