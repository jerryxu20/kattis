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
        return rank[a];
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
        rank[node2] = 0;

        max_rank = max(max_rank, rank[node1]);
        components--;
        return;
    }
};

int main() {
    ll N, M, a, b;
    cin >> N >> M;
    union_find uf(N + 1);
    while (M--) {
        cin >> a >> b ;
        uf.join(a, b);    
    }
    ll total = 0;
    ll mx = N * (N - 1) / 2;
    for (int i = 1; i <= N; i++) {
        ll r = uf.rank_of(i);
        if (r <= 1) continue;
        total += r * (r - 1) / 2;
    }
    double ans = (double) total / mx;
    // assert(ans >= 0 && ans < 1);
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}