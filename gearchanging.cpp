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
        return n;
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

    int rank_of(int a) {
        return rank[find(a)];
    }

    int comps() {
        return components;
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


bool valid(double r1, double r2, int p) {
    double rate = max(r1, r2) / min(r1, r2);
    rate -= 1;
    rate *= 100;
    cout << "rate " << rate << endl;
    return rate <= (double) p;
}
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    p += 100;
    vector<int> crank(n);
    vector<int> wheel(m);
    for (auto &t: crank) {
        cin >> t;
    }
    for (auto &t: wheel) {
        cin >> t;
    }
    sort(all(crank));
    sort(all(wheel));
    vector<double> ratios;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ratios.pb((double) crank[i] / wheel[j]);
        }
    }
    sort(all(ratios));
    for (int i = 1; i < n * m; i++) {
        if ((ratios[i] / ratios[i - 1]) * 100 > p) {
            cout << "Time to change gears!" << endl;
            return 0;
        }
    }
    cout << "Ride on!" << endl;
    return 0;
}