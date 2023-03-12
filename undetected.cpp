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

struct point {
    int id;
    int x;
    int y;
    int radius;
};


class union_find {
private:
    vector<int> id;
    vector<int> rank;
    vector<int> left;
    vector<int> right;
    int max_rank = 1;
    int components;
    int n;
    bool spans;

public:
    union_find(int N, vector<point> &points) {
        spans = false;
        id.resize(N);
        rank.resize(N);
        left.resize(N);
        right.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
            rank[i] = 1;
            left[i] = points[i].x - points[i].radius;
            right[i] = points[i].x + points[i].radius;
            if (left[i] < 0 && right[i] > 200) spans = true;
        }
        n = N;
        components = N;
    }
    bool spanning() {
        return spans;
    }

    int find(int a) {
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

    void join(int a, int b) {
        int node1 = find(a);
        int node2 = find(b);

        if (node1 == node2) return;
        if (rank[node2] > rank[node1]) {
            swap(node1, node2);
        }
        id[node2] = node1;
        rank[node1] += rank[node2];
        left[node1] = min(left[node2], left[node1]);
        right[node1] = max(right[node2], right[node1]);
        if (left[node1] < 0 && right[node1] > 200) spans = true;
        return;
    }
};

double dis(point a,point b) {
    int x = abs(a.x - b.x);
    int y = abs(a.y - b.y);
    double ans = sqrt(x*x + y*y);
    return ans;
}


int main() {
    int n, x, y, r;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        point p {i, x, y, r};
        // cout << p.x << " " << p.y << endl;
        points[i] = p;
    }
    union_find uf = union_find(n, points);
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < i; j++) {
            // cout << dis(points[i], points[j]) << " " << points[i].radius +  points[j].radius << endl;
            if (dis(points[i], points[j]) <= (points[i].radius +  points[j].radius)) {
                uf.join(i, j);
            }
        }
        if (uf.spanning()) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n - 1 << endl;
    return 0;
}