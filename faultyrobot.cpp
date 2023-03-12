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
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> forced(n + 1);
    int a, b;
    while (m--) {
        cin >> a >> b;
        adj[abs(a)].pb(b);
        if (a < 0) {
            forced[abs(a)].pb(b);
        }
    }
    // where might the robot come to a rest
    set<int> end_points;
    queue<pair<int, int>> q;
    vector<vector<bool>> seen(2, vector<bool>(n + 1));
    q.push(mp(1, 0));
    seen[0][1] = true;
    while(!q.empty()) {
        auto [node, faults] = q.front();
        q.pop();
        if (faults == 0) {
            for (auto &nxt: adj[node]) {
                if (seen[1][nxt]) continue;
                q.push(mp(nxt, 1));
                seen[1][nxt] = true;
            }
        }
        if (sz(forced[node]) == 0) {
            end_points.insert(node);
        }
        for (auto &nxt: forced[node]) {
            if (seen[faults][nxt]) continue;
            q.push(mp(nxt, faults));
            seen[faults][nxt] = true;
        }
    }
    cout << end_points.size() << endl;
    return 0;
}