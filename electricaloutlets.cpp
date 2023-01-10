#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

const int MOD_INT = 1e9 + 7;
const ll MOD = 1e9 + 7;


int main() {
    int q;
    cin >> q;
    for (int t = 1; t <= q; t++) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            ans += a;
        }
        cout << ans << endl;
    }
    return 0;
}