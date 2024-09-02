#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 2e5 + 1;
vector<int> tree[MAXN];

pi pts[MAXN];
int good[MAXN];

bool find(int x, int y) {
    if (x < 0 || x >= MAXN) return false;
    if (tree[x].size() == 0 || y > tree[x].back()) return false;

    auto it = lower_bound(tree[x].begin(), tree[x].end(), y);
    return *it == y; 
}


int main() {
    int n, m, r; cin >> n >> m >> r;
    if (m == 0) return 0;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        x += (int)1e5;
        tree[x].push_back(y);

        pts[i] = {x, y};
    }

    vector<pi> delta;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        delta.push_back({x, y});
    }
 
    for (auto &v: tree) {
        sort(v.begin(), v.end());
    }


    int valid = 0;
    pi ans;
    for (int _ = 0; _ < 4; _++) {
        for (int i = 0; i < n; i++) {
            auto [x, y] = pts[i];
            auto [a, b] = delta[0];

            x -= a;
            y -= b;

            if (find(x, y)) continue;

            int cnt = 0;
            for (int dx = -r; dx <= r; dx++) if (x + dx >= 0 && x + dx < MAXN) {
                int ymn = y - (r - abs(dx));
                int ymx = y + (r - abs(dx));
                int xx = x + dx;

                int low = lower_bound(tree[xx].begin(), tree[xx].end(), ymn) - tree[xx].begin();
                int high = upper_bound(tree[xx].begin(), tree[xx].end(), ymx) - tree[xx].begin();

                cnt += high - low;
            }
            if (cnt != m) continue;

            for (auto &[a, b]: delta) {
                int xx = x + a;
                int yy = y + b;
                if (find(xx, yy)) cnt--;
            }

            if (cnt == 0) {
                valid++;
                ans = {x, y};
            }
        }

        for (auto &[a, b]: delta) {
            swap(a, b);
            a *= -1;
        }
    }
    

    if (valid == 0) {
        cout << "Impossible\n";
        return 0;
    }

    if (valid == 1) {
        cout << ans.first - (int)1e5 << " " << ans.second << endl;
        return 0;
    }
    cout << "Ambiguous\n";
}