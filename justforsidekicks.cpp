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

struct Seg {
    int low, high, val = 0;
    Seg *left = nullptr, *right = nullptr;
    Seg(int low, int high) {
        this->low = low;
        this->high = high;
        if (low == high) return;
        int mid = (low + high)/2;
        left = new Seg(low, mid);
        right = new Seg(mid + 1, high);
        calc();
    }

    void calc() {
        if (low == high) return;
        val = left->val + right->val;
    }

    int query(int a, int b) {
        if (a <= low && high <= b) return val;
        if (high < a || low > b) return 0;
        return left->query(a, b) + right->query(a, b);
    }

    void add(int i, int x) {
        if (i < low || i > high) return;
        if (high == low) {
            val += x;
            return;
        }
        left->add(i, x);
        right->add(i, x);
        calc();
    }
};

vi val(6);

ll dot(vi &a, vi &b) {
    ll ans = 0;
    rep(i, 0, sz(a)) {
        ans += (ll)a[i] * b[i];
    }
    return ans;
}
vector<Seg> tree;
int solve(int tt) {
    int n, q; cin >> n >> q;
    trav(v, val) cin >> v;
    rep(_, 0, 6) {
        tree.pb(Seg(0, n - 1));
    }
    vector<int> g(n);
    string s; cin >> s;
    rep(i, 0, n) {
        g[i] = s[i] - '1';
        tree[g[i]].add(i, 1);
    }

    int type, k, p, v, l, r;
    while(q--) {
        cin >> type;
        if (type == 1) {
            cin >> k >> p;
            k--; p--;
            tree[g[k]].add(k, -1);
            tree[p].add(k, 1);
            g[k] = p;
        } else if (type == 2) {
            cin >> p >> v; p--;
            val[p] = v;
        } else {
            cin >> l >> r;
            l--; r--;
            vi cnt;
            trav(seg, tree) {
                cnt.pb(seg.query(l, r));
            }
            cout << dot(cnt, val) << nl;
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