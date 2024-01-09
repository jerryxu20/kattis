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
const int mx = 65536;

int m, n, val[mx];

bool disjoint(set<int> &a, set<int> &b) {
    trav(num, a) {
        if (b.count(num)) {
            return false;
        }
    }
    return true;
}

ll f(vi arr, int bitmask) {
    // left & bimask == 0, right & bitmask != 0
    vector<int> left, right;
    set<int> in_left, in_right;

    trav(num, arr) {
        if (num & bitmask) {
            right.pb(num);
            in_right.insert(val[num]);
        } else {
            left.pb(num);
            in_left.insert(val[num]);
        }
    }

    // there is no digit to partition by, so it should be impossible
    if (bitmask == 0 && sz(in_left) != 1) return 0;
    if (bitmask == 0) return 1;

    if (!disjoint(in_left, in_right)) {
        return (2 * f(arr, bitmask >> 1)) % MOD;
    }

    return (f(left, bitmask >> 1) * f(right, bitmask >> 1)) % MOD;
}

int solve(int tt) {
    cin >> m >> n;
    rep(i, 0, 1 << m) {
        cin >> val[i];
    }

    vi arr(1 << m);
    iota(all(arr), 0);

    if (m == 0) {
        cout << f(arr, 0) << endl;
        return 0;
    }
    cout << f(arr, 1 << (m - 1)) << endl;

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