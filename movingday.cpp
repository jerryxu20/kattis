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
    ll n, V, a, b, c;
    cin >> n >> V;
    ll ans = INT_MIN;
    while(n--) {
        cin >> a >> b >> c;
        ans = max(ans, a * b * c - V);
    }
    cout << ans << endl;
    return 0;
}