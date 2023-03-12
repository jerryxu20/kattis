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
    int n;
    cin >> n;
    vector<int> heights(n);
    for (auto &h: heights) {
        cin >> h;
    }

    sort(all(heights));
    int ans = n;
    rep(i, 0, n) {
        int h = heights[i];
        ans = min(h + n - (i + 1), ans);
    }
    cout << ans << endl;
    return 0;
}