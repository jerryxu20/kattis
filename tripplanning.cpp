#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> adj(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a][b] = i + 1;
        adj[b][a] = i + 1;
    }
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        if (adj[i][i + 1] == 0) {
            cout << "impossible";
            return 0;
        }
        ans.push_back(adj[i][i + 1]);
    }
    if (adj[n - 1][0] == 0) {
        cout << "impossible";
        return 0;
    }
    ans.push_back(adj[n - 1][0]);
    
    for (int line: ans) {
        cout << line << "\n";
    }
    return 0;
}