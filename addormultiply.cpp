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

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

struct Tree {
	typedef ll T;
	static constexpr T unit = 1;
	T f(T a, T b) { return (a * b) % MOD; } // (any associative fn)
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

int n, m;

tuple<Tree, Node, Node, ll>  build(string &s) {
    Node mn(0, n + 1), mx(0, n + 1);
    Tree seg(n + 1);
    ll ans = 0;
    int low = 0;
    s.pb('+');
    rep(i, 0, sz(s)) {

        if (s[i] == '+') {
            ans += seg.query(low, i);
            ans %= MOD;
            mn.set(low, i, low);
            mx.set(low, i, i - 1);
            low = i + 1;
            continue;
        }
        if (s[i] == '*') continue;
        seg.update(i, s[i] - '0');
    }

    return {seg, mn, mx, ans};
}

ll swap_query(Tree &seg, Node &mn, Node &mx, string &s, int i, int j) {
    i = (i - 1) * 2;
    j = (j - 1) * 2;

    ll delta = 0;

    int a = s[i] - '0';
    int b = s[j] - '0';

    int low = mn.query(i, i + 1);
    int high = mx.query(i, i + 1);

    delta -= seg.query(low, high + 1);
    seg.update(i, b);
    delta += seg.query(low, high + 1);

    delta %= MOD;

    low = mn.query(j, j + 1);
    high = mx.query(j, j + 1);

    delta -= seg.query(low, high + 1);
    seg.update(j, a);
    delta += seg.query(low, high + 1);
    
    delta %= MOD;

    swap(s[i], s[j]);
    return delta;
}


ll flip(Tree &seg, Node &mn, Node &mx, string &s, int i) {
    i = i * 2 - 1;
    ll delta = 0;

    if (s[i] == '+') {
        s[i] = '*';
        int low = mn.query(i - 1, i);
        int high = mx.query(i + 1, i + 2);

        // subtract away both sides
        delta -= seg.query(low, i);
        delta -= seg.query(i + 1, high + 1);

        mn.set(low, high + 1, low );
        mx.set(low, high + 1, high);

        delta += seg.query(low, high + 1);
        return delta % MOD;
    }

    s[i] = '+';

    int low = mn.query(i - 1, i);
    int high = mx.query(i + 1, i + 2);

    delta -= seg.query(low, high + 1);

    mx.set(low, i, i - 1);
    mn.set(i + 1, high + 1, i + 1);

    delta += seg.query(low, i);
    delta += seg.query(i + 1, high + 1);

    return delta % MOD;
}

int solve(int tt) {
    cin >> n >> m;
    n += n;
    string a; cin >> a;
    string b = a;
    trav(c, b) {
        if (c == '+') c = '*';
        else if (c == '*') c = '+'; 
    }

    auto [A, mn_a, mx_a, val_a] = build(a);
    auto [B, mn_b, mx_b, val_b] = build(b);
    char command;
    int i, j;
    int cur = 1;
    cout << val_a << endl;
    while(m--) {
        cin >> command;
        if (command == 's') {
            cin >> i >> j;
            val_a += swap_query(A, mn_a, mx_a, a, i, j);
            val_b += swap_query(B, mn_b, mx_b, b, i, j);
        } else if (command == 'f') {
            cin >> i;
            val_a += flip(A, mn_a, mx_a, a, i);
            val_b += flip(B, mn_b, mx_b, b, i);

        } else {
            cur *= -1;
        }
        val_a %= MOD;
        val_b %= MOD;
        if (cur == 1) {
            cout << (val_a + MOD) % MOD << nl;
        } else {
            cout << (val_b + MOD) % MOD << nl;
        }
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