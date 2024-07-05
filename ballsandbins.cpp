#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int win[3 * MAXN];
int n;

double dp[MAXN][MAXN][MAXN];
int valid[MAXN][MAXN][MAXN];

double f(int a, int b, int c, int d = 0, int won = 0) {
    if (a < 0) return 0;
    if (b < 0) return 0;
    if (c < 0) return 0;
    if (d < 0) return 0;
    
    if (valid[a][b][c]) return dp[a][b][c];
    int turn = b + 2 * c + 3 * d;
    int p = win[turn];


    // either don't roll or roll
    double roll = (double)a/n * f(a - 1, b + 1, c, d, won + p)
                + (double)b/n * f(a, b - 1, c + 1, d, won + p)
                + (double)c/n * f(a, b, c - 1, d + 1, won + p);

    dp[a][b][c] = max(roll, (double)won);
    valid[a][b][c] = 1;
    return dp[a][b][c];
}


int main() {
    cin >> n;
    for (int i = 0; i < 3*n; i++) cin >> win[i];

    cout << setprecision(12) << fixed << f(n, 0, 0, 0) << endl;
    return 0;
}