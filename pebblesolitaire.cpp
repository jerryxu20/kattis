#include <bits/stdc++.h>
using namespace std;

int dp[1 << 12];



int f(int state) {
    int mask = (1 << 1) | (1 << 2);
    int cur = (1 << 0) | (1 << 1) | (1 << 2);

    if (dp[state] != -1) return dp[state];
    int &ans = dp[state];
    ans =  __builtin_popcount(state);
    
    for (int i = 2; i < 12; i++) {
        if (((state ^ mask) & cur) == 0) {
            ans = min(ans, f(state ^ cur));
        }
        cur <<= 1;
        mask <<= 1;
    }

    mask = (1 << 0) | (1 << 1);
    cur = (1 << 0) | (1 << 1) | (1 << 2);
    for (int i = 2; i < 12; i++) {
        if (((state ^ mask) & cur) == 0) {
            ans = min(ans, f(state ^ cur));
        }
        cur <<= 1;
        mask <<= 1;
    }

    return ans;
}


int main() {
    memset(dp, -1, sizeof(dp));

    int n; cin >> n;
    while(n--) {
        string s; cin >> s;

        int st = 0;
        for (int i = 0; i < 12; i++) {
            if (s[i] == 'o') st |= (1 << i);
        }

        cout << f(st) << "\n";
    }


}