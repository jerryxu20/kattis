#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 500;

int grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int f(int l, int r) {
    if (l == r) return 0;
    
    int &ans = dp[l][r];
    if (ans != -1) return ans;

    ans = 0;
    
    for (int i = (l + 1) % n; i != r; i = (i + 1) % n) {
        // try connecting l to i
        int cand = grid[l][i] + f((i + 1) % n, r);
        if ((l + 1) % n != i) {
            cand += f((l + 1) % n, (i - 1 + n) % n);
        }

        ans = max(ans, cand);

        // try connecting i to r
        cand = grid[i][r] + f(l, (i - 1 + n) % n);
        if ((i + 1) % n != r) {
            cand += f((i + 1) % n, (r - 1 + n) % n);
        }
        ans = max(ans, cand);
    }

    // connect l to r
    int cand = grid[l][r];
    if ((l + 1) % n != r) {
        cand +=  f((l + 1) % n, (r - 1 + n) % n);
    }
    ans = max(ans, cand);

    
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, n - 1) << endl; 
}