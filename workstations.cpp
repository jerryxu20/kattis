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
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> rs(n);
    for (auto &[a, b]: rs) {
        cin >> a >> b;
    }
    sort(all(rs));
    priority_queue<ll, vector<ll>, greater<ll>> lock;
    int ans = 0;
    for (auto &[a, b]: rs) {
        // removed locked rooms
        while(!lock.empty() && lock.top() + m < a) {
            lock.pop();
        }
        if (lock.empty() || lock.top() > a) ans++;
        else lock.pop();
        lock.push(a + b);
    }
    cout << n - ans << endl;
    return 0;
}