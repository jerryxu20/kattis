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
    int l, w;
    cin >> l >> w;
    if (w < l || w > l * 26) {
        cout << "impossible\n";
        return 0;
    }
    string ans = "";
    int avg = w / l;
    while (l--) {
        ans += char(avg + (int) 'a' - 1);
        w -= avg;
        if (l <= 0) {
            break;
        }
        avg = w / l;
    }
    cout << ans << endl;
    return 0;
}