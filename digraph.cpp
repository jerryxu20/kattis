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

void dfs(int node, vector<int> &dp, vector<int> &seen, vector<int> &parent, vector<vector<bool>>&adj, int &start, int &end) {
    if (seen[node] == 2 || start != -1) return;
    seen[node] = 1;
    for (int i = 0; i < 26; i++) {
        if (!adj[node][i]) continue;
        if (seen[i] == 1) {
            start = i;
            end = node;
            return;
        }
        if (seen[i] == 0) {
            parent[i] = node;
            dfs(i, dp, seen, parent, adj, start, end);
        }
        if (start != -1) return;
        dp[node] = max(dp[node], dp[i] + 1);
    }
    seen[node] = 2;
    return;
}

int solve() {
    vector<int> dp(26);
    vector<int> seen(26);
    vector<int> parent(26, -1);
    vector<vector<bool>> adj(26, vector<bool>(26, true));
    int n;
    string a;
    cin >> n;
    while(n--) {
        cin >> a;
        adj[a[0] - 'a'][a[1] - 'a'] = false;
    } 
    int c_start = -1;
    int c_end = -1;
    for (int i = 0; i < 26; i++) {
        dfs(i, dp, seen, parent, adj, c_start, c_end);
        if (c_start != -1) break;
    }

    if (c_start != -1) {
        vector<int> cycle = {c_start};
        for (int i = c_end; i != c_start; i = parent[i]) {
            cycle.pb(i);
        }
        reverse(all(cycle));
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                int idx = (i + j) % sz(cycle);
                cout << char(cycle[idx] + 'a');
            }
            cout << endl;
        }
        return 0;
    }
    int cur = 0;
    for (int i = 0; i < 26; i++) {
        if (dp[i] > dp[cur]) cur = i;
    }
    vector<int> path;
    while(dp[cur] > 0) {
        path.pb(cur);
        for (int i = 0; i < 26; i++) {
            if (adj[cur][i] && dp[i] + 1 == dp[cur]) {
                cur = i;
                break;
            }
        }
    }
    path.pb(cur);
    int len = (sz(path) + 1) / 2;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int idx = (i + j) % sz(path);
            cout << char(path[idx] + 'a');
        }
        cout << endl;
    }
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