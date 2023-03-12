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
    int m, p, n, t;
    cin >> m >> p >> n;
    vector<int> times(n);
    int ans = 0;
    int tax = 0;
    int target;
    while (n--) {
        cin >> t;
        target = m + tax;
        tax = target - t;
        if (tax <= 0) {
            ans++;
        }
        tax = ceil(tax * p / 100.0);
    }
    cout << ans << endl;
    
    
    return 0;
}