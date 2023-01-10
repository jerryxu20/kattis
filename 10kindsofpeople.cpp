#include <bits/stdc++.h>
using namespace std;

class union_find {
private:
    vector<int> id;
    vector<int> rank;
    int max_rank = 1;
    int components;
    int n;

public:
    union_find(int N) {
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
        int root = a;
        while (root != id[root]) {
            root = id[root];
        }
        // while (a != root) {
        //     int nxt = id[a];
        //     id[a] = root;
        //     a = nxt;
        // }
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

int mapping(int row, int col, int r, int c) {
    return (row * c) + col;
}

int main() {
    int r, c;
    cin >> r >> c;
    int n = r * c;
    vector<vector<int>> grid(r);
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (char &c: s) {
            grid[i].push_back(c - '0');
        }
    }
    union_find uf = union_find(n);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i > 0 && grid[i - 1][j] == grid[i][j]) {
                uf.join(mapping(i, j, r, c), mapping(i - 1, j, r, c));
            }
            if (j > 0 && grid[i][j - 1] == grid[i][j]) {
                uf.join(mapping(i, j, r, c), mapping(i, j - 1, r, c));
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        r2--;
        c1--;
        c2--;
        if (uf.connected(mapping(r1, c1, r, c), mapping(r2, c2, r, c))) {
            if (grid[r1][c1] == 0) {
                cout << "binary\n";
            } else {
                cout << "decimal\n";
            }
        } else {
            cout << "neither\n";
        }
    }
    return 0;
}