#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair

int solve() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> canvas(n);
    for (auto &c: canvas) {
        cin >> c;
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq (canvas.begin(), canvas.end());
    while(sz(pq) > 1) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans << endl;
    assert(ans >= 0);
    return 0;
}

int main() {
    int tcase = 1;
    cin >> tcase;
    for (int i = 1; i <= tcase; i++) {
        solve();
    }
    return 0;
}