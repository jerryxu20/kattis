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
    int a, b, c;
    cin >> a >> b >> c;
    vi hor = {a - b, b};
    vi ver = {a - c, c};
    int ans = 0;
    for (auto &h: hor) {
        for (auto &v: ver) {
            ans = max(ans, h * v * 4);
        }
    }
    cout << ans << endl;
    return 0;
}