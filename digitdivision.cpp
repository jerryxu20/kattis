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
    ll n, m;
    string s;
    cin >> n >> m >> s;
    ll num = 0;
    ll mod = 1e9 + 7;
    ll parts = 0;
    for (int i = 0; i < (int)n; i++) {
        num *= 10;
        num += s[i] - '0';
        num %= m;
        if (num == 0) {
            parts++;
        }
    }
    // number is not divisible 
    if (num != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    parts--;
    while (parts--) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}