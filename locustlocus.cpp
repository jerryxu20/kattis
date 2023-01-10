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
    int n;
    cin >> n;
    int ans = INT_MAX;
    while (n--) {
        int y, c1, c2;
        cin >> y >> c1 >> c2;
        int year = lcm(c1, c2) + y;
        ans = min(ans, year);
    }
    cout << ans << endl;
    return 0;
}