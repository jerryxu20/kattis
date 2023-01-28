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
    int n;
    cin >> n;
    // there are n topics to discuss
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int dep;
    vector<int> out_deg (n);
    vector<vector<int>> adj(n);
    vector<int> times   (n);
    int a;
    for (int i = 0; i < n; i++) {
        // number of mins, number of dependencies
        cin >> times[i] >> dep;
        while (dep--) {
            cin >> a;
            out_deg[a - 1]++;
            adj[i].push_back(a -  1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (out_deg[i]-- == 0) {
            pq.push(mp(times[i], i));
        }
    }
    int ans = 0;
    int before = n - 1;
    while (!pq.empty()) {
        auto [t, node] = pq.top();
        pq.pop();
        ans = max(ans, t + before);
        before--;
        for (int nxt: adj[node]) {
            if (out_deg[nxt]-- == 0) {
                pq.push(mp(times[nxt], nxt));
            }
        }
    }
    cout << ans << endl;
    return 0;
}