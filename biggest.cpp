#include <bits/stdc++.h>
using namespace std;


int diff(int a, int b) {
    int ans = b - a;
    if (ans < 0) ans += 1296000;
    return ans;
}

int seen[1296000];
int T = 1;

void solve() {
    T++;
    int r, n, theta;
    int minute, second;
    cin >> r >> n >> theta >> minute >> second;
    if (n == 1) {
        cout << fixed << setprecision(15) <<  M_PI * r * r << endl;
        return;
    }
    theta *= 60 * 60;
    theta += minute * 60;
    theta += second;

    int cur = 0;
    while(seen[cur] != T && n--) {
        seen[cur] = T;
        cur += theta;
        cur %= 1296000;
    }

    vector<int> angle;
    for (int i = 0; i < 1296000; i++) {
        if (seen[i] == T) angle.push_back(i);
    }


    int ans = 0;
    int k = angle.size();
    for (int i = 0; i < k; i++) {
        int j = (i + 1) % k;
        ans = max(ans, diff(angle[i], angle[j]));
    }


    cout << fixed << setprecision(15) << ans/1296000.0 * M_PI * r * r << endl;
}

int main() {
    int m; cin >> m;
    while(m--) solve();
}