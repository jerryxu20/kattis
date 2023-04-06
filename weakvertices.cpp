#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    while (cin >> n) {
        if (n == -1) break;
        vector<vector<bool>> adj(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a;
                cin >> a;
                if (a) {
                    adj[i][j] = true;
                }
            }
        }
        set<int> weak;
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == false) continue;
                for (int k = 0; k < n; k++) {
                    if (adj[i][k] == false) continue;
                    if (j == k) continue;
                    if (adj[j][k]) found = true;
                }
            }
            if (!found) weak.insert(i);
        }
        for (auto &x: weak) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
    
}