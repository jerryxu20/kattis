#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000;
int adj[MAXN][MAXN];


int main() {
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        string res; cin >> res;
        for (int j = 0; j < i; j++) {
            adj[i][j] = res[j] - '0';
            adj[j][i] = adj[i][j] ^ 1;
        }
    }

    vector<int> bal(n);    
    for (int i = 0; i < n; i++) {
        bal[i] = count(adj[i], adj[i] + n, 0) - 1;
    }

    int ans = 0;
    int cur = 0;

    sort(bal.begin(), bal.end());
    for (int i = 0; i < n; i++) {
        bal[i] -= i;
        cur += bal[i];
        ans = max(ans, cur);
    }

    cout << ans << endl;
}