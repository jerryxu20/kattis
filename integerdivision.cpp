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
    int n, d;
    cin >> n >> d;
    map<int, int> results;
    set<int> nums;
    ll ans = 0;
    while (n--) {
        int a;
        cin >> a;
        ans += results[a / d]++;
    }
    cout << ans << "\n";
    return 0;
}