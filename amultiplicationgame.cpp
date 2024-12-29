#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
map<ll, int> dp;
int f(ll x) {
    if (dp.count(x)) return dp[x];
    if (x >= n) return 0;
    for (int i = 2; i <= 9; i++) {
        if (f(x * i) == 0) {
            dp[x] = 1;
            return 1;
        }
    }
    dp[x] = 0;
    return 0;
}

int main() {
    while(cin >> n) {
        dp.clear();
        if (f(1)) {
            cout << "Stan wins.\n";
        } else {
            cout << "Ollie wins.\n";
        }
    }
}