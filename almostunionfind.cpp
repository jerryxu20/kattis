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
    vector<ll> id;
    vector<ll> rank;
    vector<ll> mapping;
    vector<ll> n_rank;
    ll max_rank = 1;
    ll components;
    ll n;

public:
    union_find(ll N) {
        id.resize(N);
        rank.resize(N);
        mapping.resize(N);
        n_rank.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
            rank[i] = 1;
            mapping[i] = i;
            n_rank[i] = i;
        }
        n = N;
        components = N;
    }

    void reset(ll N) {
        id.resize(N);
        rank.resize(N);
        mapping.resize(N);
        n_rank.resize(N);
        for (ll i = 0; i < N; i++) {
            id[i] = i;
            rank[i] = 1;
            mapping[i] = i;
            n_rank[i] = i;
        }
        n = N;
        components = N;   
    }

    int size() {
        return n;
    }

    int find(ll a) {
        a = mapping[a];
        ll root = a;
        while (root != id[root]) {
            root = id[root];
        }
        while (a != root) {
            ll nxt = id[a];
            id[a] = root;
            a = nxt;
        }
        return root;
    }

    ll rank_of(ll a) {
        return rank[find(a)];
    }

    ll n_rank_of(ll a) {
        return n_rank[find(a)];
    }

    void move(ll a, ll b) {
        if (a == b) return;
        if (find(a) == find(b)) return;
        ll i = n++;
        rank[find(a)]--;
        rank[find(b)]++;
        n_rank[find(b)] += a;
        n_rank[find(a)] -= a;
        n_rank.push_back(0);
        id.push_back(find(b));
        rank.push_back(0);
        mapping[a] = i;
        mapping.push_back(i);
        mapping[mapping[a]] = i;
        return;
        // move a to b
    }


    void join(ll a, ll b) {
        ll node1 = find(a);
        ll node2 = find(b);

        if (node1 == node2) return;
        id[node2] = node1;
        rank[node1] += rank[node2];
        n_rank[node1] += n_rank[node2];
        n_rank[node2] = 0;
        rank[node2] = 0;
        return;
    }
};

int main() {
    int n, m, a, b, c;
    union_find uf = union_find(1);
    while (cin >> n >> m) {
        uf.reset(n + 1);
        while (m--) {
            cin >> a;
            if (a == 1) {
                cin >> b >> c;
                uf.join(b, c);
            } else if (a == 2) {
                cin >> b >> c;
                uf.move(b, c);
            } else {
                cin >> b;
                if (b == 3) {
                    cout << "";
                }
                cout << uf.rank_of(b) << " " << uf.n_rank_of(b) << "\n";
            }
        }
    }
    return 0;
}