#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e7 + 1;

ll dp[MAXN];
int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    auto cnt = [] (int low, int high, int f) {
        int l = low % f;
        low += (f - l) % f;

        int h = high % f;
        high -= h;
        return max(0, (high - low)/f + 1);
    };


    for (int i = MAXN - 1; i >= 1; i--) {
        ll x = cnt(a, b, i);
        ll y = cnt(c, d, i);
        
        dp[i] = x * y;
        for (int j = i + i; j < MAXN; j += i) {
            dp[i] -= dp[j];
        }
    }
    cout << dp[1] << endl;
}