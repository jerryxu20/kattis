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

void solve() {
    int t, x, y;
    cin >> t >> x >> y;
    if (y > x) {
        cout << t << " " << 2 << " " << x << " " << y << endl;
        return;
    }
    if (y < 4) {
        cout << t << " NO PATH" << endl;
        return;
    }
    cout << t << " " <<  6 << " ";
    cout << 1 << " " << 2 << " " << 3 << " ";
    int right = 2 + x;
    int up = right + 1;
    int down = up - (y - 2);
    cout << down << " " << right << " " << up << endl;

}

int main() {
    // find a sequence of number that sum to x, such that a1, a2, a3, a4 .. bring me from (0, 0) to (x, y);
    // 0 mod 4 x++
    // 1 mod 4 y++
    // 2 mod 4 x--
    // 3 mod 4 y--
    // (x, y) is (10000, 10000);
    // each path is 22 segments
    // (y must be larger than x)
    int test;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}