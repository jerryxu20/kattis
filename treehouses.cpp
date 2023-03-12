#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

class union_find {
private:
    vector<int> id;
    vector<int> rank;
    int max_rank = 1;
    int components;
    int n;

public:
    union_find(int N) {
        //if (N < 0) {
        //	cout << "NEGATIVE" << endl;
        //	return;
        //}
        id.resize(N);
        rank.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
            rank[i] = 1;
        }
        n = N;
        components = N;
    }

    int size() {
        return components;
    }

    int find(int a) {
        // if (a < 0) {
        //	cout << "NEGATIVE" << endl;
        //	return -1;
        //}
        //if (a >= n) {
        //	cout << "TOO BIG" << endl;
        //	return -1;
        // }
        int root = a;
        while (root != id[root]) {
            root = id[root];
        }
        while (a != root) {
            int nxt = id[a];
            id[a] = root;
            a = nxt;
        }
        return root;
    }

    int rank_of(int a) {
        return rank[find(a)];
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    void join(int a, int b) {
        int node1 = find(a);
        int node2 = find(b);

        if (node1 == node2) return;
        if (rank[node2] > rank[node1]) {
            swap(node1, node2);
        }
        id[node2] = node1;
        rank[node1] += rank[node2];

        max_rank = max(max_rank, rank[node1]);
        components--;
        return;
    }
};

int main() {
    int n, e, m, a, b;
    cin >> n >> e >> m;
    union_find uf(n + 1);
    vector<pair<double, double>> coords(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }
    for (int i = 1; i <= e; i++) {
        uf.join(1, i);
    }
    while(m--) {
        cin >> a >> b;
        uf.join(a, b);
    }
    if (uf.size() == 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<tuple<double, int, int>> edges;
    for (int i = 1; i + 1 <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double dx = abs(coords[i].first - coords[j].first);
            double dy = abs(coords[i].second - coords[j].second);
            edges.pb({dx * dx + dy * dy, i, j});
        }
    }
    double ans = 0;
    sort(all(edges));
    for (auto &[weight, i, j]: edges) {
        if (uf.connected(i,j)) continue;
        uf.join(i, j);
        ans += sqrt(weight);
        if (uf.size() == 2) break;
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}