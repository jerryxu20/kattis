#include <bits/stdc++.h>
using namespace std;
// [A, n - B]
int help(int A, int B, int n) {
    int low = max(0, n - B);
    int high = min(n, A);
    return max(0, high - low + 1);
}

int solve() {
    int A, B; cin >> A >> B;
    long long ans = 0;
    for (int i = 1; i <= 30; i++) {
        ans += help(A, B, (1 << i) - 1);
    }
    cout << ans + 1 << endl;
    return 0;
}


int main() {
    int n; cin >> n;
    while(n--) {
        solve();
    }
}