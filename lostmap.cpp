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
    union_find uf = union_find(n + 1);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int d;
            cin >> d;
            if (i == j) continue;
            pq.push({d, min(i, j), max(i, j)});
        }
    }
    set<pair<int, int>> seen;
    int ans = n - 1;
    while (ans--) {
        pair<int, int> p;
        do {
            auto v = pq.top();
            pq.pop();
            p = mp(v[1], v[2]);
        } while (uf.connected(p.first, p.second));
        cout << p.first << " " << p.second << endl;
        uf.join(p.first, p.second);
    }  
    return 0;
}