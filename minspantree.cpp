#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class UF {
public:
    vi rank;
    vi id;
    int comps;
    UF(int n) {
        rank = vi(n, 1);
        id = vi(n);
        iota(all(id), 0);
    }

    int find(int a) {
        if (id[a] == a) return a;
        id[a] = find(id[a]);
        return id[a];
    }

    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[b] > rank[a]) swap(a, b);
        rank[a] += rank[b];
        rank[b] = 0;
        id[b] = a;
        comps--;
        return true;
    }
};

int solve(int tcase) {
    int n, m;
    cin >> n >> m;
    if (n == 0) return 1;
    vector<tii> edges(m);
    for (auto &[weight, a, b]: edges) {
        cin >> a >> b >> weight;
    }
    sort(all(edges));
    UF uf(n);
    vpii ans;
    int cost = 0;
    for (auto &[weight, a, b]: edges) {
        if (uf.comps == 1) break;
        if (uf.join(a, b)) {
            ans.pb(mp(min(a, b), max(a, b)));
            cost += weight;
        }
    }
    if (sz(ans) != n - 1) {
        cout << "Impossible\n";
    } else {
        sort(all(ans));
        cout << cost << endl;
        for (auto &[a, b]: ans) {
            cout << a << " " << b << endl;
        }
    }
    return 0;
}

int main() {
    int testcase = 1;
    // cin >> testcase;
    // for (int i = 1; i <= testcase; i++) {
    //     solve(i);
    // }
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    return 0;
}