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
    int e, m;
    int t = 1;
    while(cin >> e >> m) {
        int ans = 0;
        if (e != 0) {
            m += 365 - e;
            ans = 365 - e;
        }
        m %= 687;
        while(m != 0) {
            m += 365;
            m %= 687;
            ans += 365;
        }
        cout << "Case " << t++ << ": " << ans << endl;
    }
    return 0;
}