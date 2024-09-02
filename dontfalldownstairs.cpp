#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> height(n + 1);
    for (int i = 0; i < n; i++) cin >> height[i];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x = height[i];
        int y = height[i + 1];

        if (x - y > 1) {
            ans += (x - y - 1);
        }
    }
    cout << ans << endl;

}