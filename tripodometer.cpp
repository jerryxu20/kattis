#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int dis[MAXN];
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> dis[i];
    int sm = accumulate(dis, dis + n, 0);

    set<int> ans;
    for (int i = 0; i < n; i++) {
        ans.insert(sm - dis[i]);
    }

    cout << ans.size() << endl;
    for (auto &x: ans) {
        cout << x << " ";
    }
    cout << endl;
}