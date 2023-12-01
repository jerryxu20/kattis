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

const ll inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = 0;
    Node(int lo, int hi): lo(lo), hi(hi) {}
    Node(vi &v, int lo, int hi): lo(lo), hi(hi) {
        if (lo  + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = min(l->val, r->val);
        } else val = v[lo];
    }
    ll query(int L, int R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return val;
        push();
        return min(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = min(l->val, r->val);
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
            val = min(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf) 
            l->set(lo, hi, mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo, hi,madd), r->add(lo, hi, madd), madd = 0;
    }

};


int solve(int tt) {
    int n; cin >> n;
    int prev = 0;
    vl times;
    vector<pi> trips;
    int cur, t;
    rep(i, 0, n) {
        cin >> cur >> t;
        trips.pb({min(cur, prev), max(cur, prev)}); 
        times.pb(t);
        prev = cur;
    }

    Node seg(0, n + 1);
    // mx[i]: the range of nodes whose mx is i
    // mn[i]: the range of nodes whose mn is i
    vector<pi> mx(11, {-1, -1}), mn(11, {-1, -1});

    ll ans = 0;
    rep(i, 0, sz(trips)) {

        auto [a, b] = trips[i];
        
        // update bounds of a, b
        if (mn[a].first == -1) {
            mn[a] = {i, i};
        } else {
            mn[a].second = i;
        }
        if (mx[b].first == -1) {
            mx[b] = {i, i};
        } else {
            mx[b].second = i;
        }

        seg.add(i, i + 1, 2 + (b - a));
        
        // update the cost of nodes whose mx is less than us
        rep(j, 0, b) {
            auto [low, high] = mx[j];
            if (low == -1) continue;

            seg.add(low, high + 1, b - j);
            // update bounds
            mx[b].first = min(mx[b].first, low);
            mx[b].second = max(mx[b].second, high);

            mx[j] = {-1, -1};
        }
        // update the cost of nodes whose mn is more than us
        rep(j, a + 1, 11) {
            auto [low, high] = mn[j];
            if (low == -1) continue;

            seg.add(low, high + 1, j - a);

            // update bounds
            mn[a].first = min(mn[a].first, low);
            mn[a].second = max(mn[a].second, high);

            mn[j] = {-1, -1};
        }

        int idx = lower_bound(all(times),  times[i]-10000) - times.begin();
        ans = seg.query(idx, i + 1);
        seg.add(i + 1, i + 2, ans);
    }
    cout << ans << nl;
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