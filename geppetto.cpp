#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> banned(n);
    while(m--) {
        int a, b; cin >> a >> b;
        a--; b--;
        banned[a] |= (1 << b);
        banned[b] |= (1 << a);
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int add = 1;
        for (int j = 0; j < n; j++) if (i & (1 << j)) {
            if (i & banned[j]) add = 0;
        }
        ans += add;
    }

    cout << ans << endl;
}