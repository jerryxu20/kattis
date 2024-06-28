#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pi>> adj(n);

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
    }

    double low = 0;
    double high = 2e6;
    double ans = 0;


    auto valid = [&] (double x) {
        vector<double> seen(n, -1e18);
        seen[0] = 0;
        for (int i = 0; i < n; i++) {
            for (auto &[nxt, w]: adj[i]) {
                seen[nxt] = max(seen[nxt], w - x + seen[i]);
            }
        }
        return seen.back() >= 0;
    };

    int k = 50;
    while(k--) {
        double mid = (low + high)/2;
        if (valid(mid)) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
}