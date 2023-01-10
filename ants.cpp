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
        int l, n;
        cin >> l >> n;
        int close = 0;
        int far = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            far = max({far, a, l - a});
            close = max(close, min(a, l - a));
        }
        cout << close << " " << far << endl;
        

    }
    return 0;
}