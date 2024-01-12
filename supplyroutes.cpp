#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;
typedef tuple<int,int,int> ti;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vii;
typedef vector<vii> viii;

template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for (int i=a; i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a)-1; i >= 0; i--)
#define trav(x,A) for (auto& x : A)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

struct UF {
    vi id;
    UF(int n) {
        id.resize(n);
        iota(all(id), 0);
    }

    int find(int a) {
        if (a == id[a]) return a;
        id[a] = find(id[a]);
        return id[a];
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        id[a] = b;
        return;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};


int solve(int tt) {
    int n, m, q; cin >> n >> m >> q;

    vpi edges(m);
    for (auto &[a, b]: edges) {
        cin >> a >> b;
    }

    vector<ti> queries(q);
    set<pi> destroyed;
    for (auto &[type, a, b]: queries) {
        cin >> type >> a >> b;
        if (type == 0) {
            destroyed.insert(mp(a, b));
        }
    }

    UF uf(n);
    for (auto &[a, b]: edges) {
        if (!destroyed.count(mp(a, b))) {
            uf.join(a, b);
        }
    }

    reverse(all(queries));
    vector<string> ans;
    for (auto &[type, a, b]: queries) {
        if (type == 0) {
            uf.join(a, b);
        } else {
            ans.pb( (uf.connected(a, b) ? "safe": "unsafe") ); 
        }


    }

    FORd(i, 0, sz(ans)) {
        cout << ans[i] << nl;
    }

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}