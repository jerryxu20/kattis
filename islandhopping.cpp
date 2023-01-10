#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

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
        return n;
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
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        vector<pair<double, double>> coords;
        union_find uf = union_find(m);
        for (int i = 0; i < m; i++) {
            double x, y;
            cin >> x >> y;
            coords.pb(mp(x, y));
        }
        vector<pair<double, pair<double, double>>> edges;
        for (int i = 0; i < m; i++) {
            for (int j = i - 1; j >= 0; j--) {
                double d = sqrt((coords[j].first - coords[i].first) * (coords[j].first - coords[i].first) + (coords[j].second - coords[i].second) * (coords[j].second - coords[i].second));
                edges.pb(mp(d, mp(i, j)));
            }
        }
        sort(all(edges), [] (auto &a, auto &b) {
           return a.first < b.first; 
        });
        int num = 0;
        double ans = 0;
        for (auto &edge: edges) {
            if (uf.connected(edge.second.first, edge.second.second)) continue;
            uf.join(edge.second.second, edge.second.first);
            ans += edge.first;
            num++;
            if (num == m - 1) break;
        }
        cout << setprecision(64) << ans << endl;
    }
    return 0;
}