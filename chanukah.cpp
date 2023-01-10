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
        int k, n;
        cin >> k >> n;
        cout << k << ' ' << n * (n + 1)/2 + n << '\n';
    }
    return 0;
}