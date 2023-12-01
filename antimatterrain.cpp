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
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
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

vector<int> X;
int N = 0;
map<int, int> ID;
int id(int x) {
    if (ID.count(x)) return ID[x];
    ID[x] = N++;
    return ID[x];
}

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int solve(int tt) {
    int n, m; cin >> n >> m;

    vector<ti> items;
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        items.pb({y, x, -i});
        X.pb(x);
    }

    rep(_, 0, m) {
        int a, b, y;
        cin >> a >> b >> y;
        items.pb({y, a, b});
        X.pb(a);
        X.pb(b);
    }

    sort(all(X));
    rep(i, 0, sz(X)) {
        id(X[i]);
    }

    sort(all(items), [](auto &a, auto &b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
        return get<1>(a) < get<1>(b);
    });

    Tree seg(N);
    map<int, set<pi>> Y;
    vector<vi> line(N);
    vi ans(n);
    for (auto &[y, a, b]: items) {
        // this is a rain drop
        if (b <= 0) {
            int x = id(a);
            int idx = -b;
            Y[y].insert({x, idx});
            line[x].pb(y);
            seg.update(x, y);
            continue;
        }
        a = id(a);
        b = id(b);
        int hit = seg.query(a, b + 1);
        if (hit == INT_MAX) continue;

        set<pi> &pts = Y[hit];

        auto it = pts.lower_bound({a, 0});
        vpi removed;
        while(it != pts.end()) {
            auto [xx, idx] = *it;
            assert(xx >= a);
            if (xx > b) break;

            // The current sensor will hit this point
            ans[idx] = y;
            removed.pb({xx, idx});

            // Update the value of this point
            int val = INT_MAX;
            vi &stack = line[xx];
            assert(stack.back() == hit);

            // Replace with higher point
            stack.pop_back();
            if (sz(stack)) {
                val = stack.back();
            }
            seg.update(xx, val);
            it++;
        }

        trav(p, removed) pts.erase(p);
    }

    trav(a, ans) {
        cout << a << nl;
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