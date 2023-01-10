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
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n + m == 0) break;
        union_find uf = union_find(n);
        vector<vector<int>> edges;
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            edges.pb({w, a, b});
        } 
        sort(all(edges));
        int cost = 0;
        int taken = 0;
        vector<pair<int, int>> ans;
        for (auto &edge: edges) {
            if (uf.connected(edge[1], edge[2])) continue;
            uf.join(edge[1], edge[2]);
            ans.pb(mp(min(edge[1], edge[2]), max(edge[1], edge[2])));
            cost += edge[0];
            taken++;
            if (taken == n - 1) break;
        }
        if (taken == n - 1) {
            cout << cost << "\n";
            sort(all(ans));
            for (auto &p: ans) {
                cout << p.first << " " << p.second << "\n";
            }
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}