#include <bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> id, rank;
    UF (int n): id(n), rank(n, 1) {
        iota(id.begin(), id.end(), 0);
    }

    int find(int a) {
        if (id[a] == a) return id[a];
        id[a] = find(id[a]);
        return id[a];
    }

    bool join(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);

        id[b] = a;
        rank[a] += rank[b];
        return true;
    }
};

void solve() {
    int x, n; cin >> x >> n;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n * (n - 1)/2; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    x -= n;
    sort(edges.begin(), edges.end());

    UF uf(n);
    for (auto &[c, a, b]: edges) {
        if (uf.join(a, b)) x -= c;
    }

    if (x >= 0) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}


int main() {
    int t; cin >> t;
    while(t--) solve();
}