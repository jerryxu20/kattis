#include <bits/stdc++.h>
using namespace std;

const int m = 1334;
int main() {
    int n; cin >> n;

    bitset<m> dp;
    dp[0] = 1;


    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];


    for (int &x: weights) {
        dp |= (dp << x);
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {

        if (dp[i] && abs(1000 - i) <= abs(1000 - ans)) ans = i;
    }
    cout << ans << endl;
}