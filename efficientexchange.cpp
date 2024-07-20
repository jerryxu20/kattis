#include <bits/stdc++.h>
using namespace std;

int dp[1005][2];


int dfs(int idx, int carry, string &s) {
    if (idx == (int)s.size()) return carry;
    int d = s[idx] - '0';

    if (dp[idx][carry] != -1) return dp[idx][carry];
    if (carry == 0) {
        dp[idx][carry] =  min({d + dfs(idx + 1, 0, s),
                    10 - d + 1 + dfs(idx + 1, 0, s),
                    9 - d + 1 + dfs(idx + 1, 1, s)});
    } else {
        dp[idx][carry] =  min({
            1 + d + dfs(idx + 1, 0, s),
            10 - d + dfs(idx + 1, 0, s),
            9 - d + dfs(idx + 1, 1, s)
        });
    }
    return dp[idx][carry];
}

int main() {
    string s; cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0,s) << endl;
}