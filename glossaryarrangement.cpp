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
    vector<int> num;
    int max_rank = 0;
    int components;
    int n;

public:
    union_find(int N, vector<string> &words) {
        id.resize(N);
        rank.resize(N);
        num.resize(N);
        max_rank = N - 1;
        for (int i = 0; i < N; i++) {
            id[i] = i;
            rank[i] = sz(words[i]);
            max_rank += sz(words[i]);
            num[i] = 1;
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

    int len(int a) {
        return rank[find(a)];
    }

    int rows(int a) {
        return num[find(a)];
    }

    int width() {
        return max_rank;
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
        rank[node1] = max(rank[node1], rank[node2]);
        num[node1] += num[node2];
        max_rank -= rank[node2];
        max_rank--;
        // components--;
        return;
    }
};
map<string, int> id;
vector<string> words;
int n, w;
struct comp {
    // choose between two pairs
    bool operator() (pii &a, pii &b) {
        int node1 = min(sz(words[a.first]), sz(words[a.second]));
        int node2 = min(sz(words[b.first]), sz(words[b.second]));
        if (node1 == node2) return sz(words[a.first]) < sz(words[a.second]);
        return node1 < node2;
    }
};

bool possible(priority_queue<pii> &pq, int rows, union_find &uf) {
    if (uf.width() <= w) return true;
    while(!pq.empty()) {
        auto [a, b] = pq.top();
        pq.pop();
        if (uf.rows(a) + uf.rows(b) > rows) continue;
        if (uf.rows(a) + uf.rows(b) <= rows) uf.join(a, b);
        if (uf.width() <= w) return true;
        // we joined a and b, which exposes a new edge
        
    }
}

int main() {
    cin >> n >> w;
    words.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        id[words[i]] = i;
    }
    priority_queue<pii, vector<pii>, comp> pq;
    for (int i = 1; i < n; i++) {
        pq.push(mp(i - 1, i));
    }
    int low = 0;
    int high = n;
    int ans = n;
    union_find state;
    union_find ufind(n, words);
    while(low <= high) {
        int mid = (low + high) / 2;
        if (possible(pq, mid, ufind)) {
            ans = min(ans, mid);
            high = mid - 1;
            state = ufind;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        cout << sz(words[p.first]) << " " << sz(words[p.second]) << endl;
    }
    return 0;
}