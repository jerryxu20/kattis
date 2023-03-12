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
    int t, n;
    cin >> t >> n;
    int x = 0;
    int y = 0;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (i % 4 == 0) {
            x += a;
        } else if (i % 4 == 1) {
            y += a;
        } else if (i % 4 == 2) {
            x -= a;
        } else {
            y -= a;
        }
    }
    cout << x << " " << y << endl;
    
    return 0;
}