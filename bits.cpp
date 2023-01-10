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
    int test, x;
    cin >> test;

    while (test--) {
        cin >> x;
        string s = to_string(x);
        int num = 0;
        int ans = 0;
        for (char &c: s) {
            num *= 10;
            num += c - '0';
            ans = max(ans, __builtin_popcount(num));
        }
        cout << ans << endl;
        
    }
    return 0;
}