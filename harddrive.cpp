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
    // some bits are always 0, the first bit can be changed, the last bit is zero
    int n, c, b;
    cin >> n >> c >> b;
    // bits, changes, broken
    vector<bool> fixed (n);
    int a;
    while (b--) {
        cin >> a;
        fixed[a - 1] = true;
    }
    // since the last is always zero, if I want an odd number of changes, I must set the first bit
    vector<int> ans(n);
    if (c % 2 == 1) {
        ans[0] = 1;
        c--;
    }
    int idx = 1;
    c /= 2;
    while (c--) {
        while (idx < n && (fixed[idx] || ans[idx - 1] == 1)) {
            idx++;
        }
        if (idx >= n) break;
        ans[idx] = 1;
        idx++;
    }
    for (int bit: ans) {
        cout << bit;
    }
    cout << endl;
    return 0;
}