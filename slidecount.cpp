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
    int low, high, val = 0, stored = 0;
    Seg *left = nullptr;
    Seg *right = nullptr;
    
    Seg(int n) : Seg(0, n - 1) {};

    Seg(int _low, int _high) {
        low = _low;
        high = _high;
        if (low == high) return;
        int part = (low + high)/2;
        left = new Seg(low, part);
        right = new Seg(part + 1, high);
    }

    // increment all values in [low, high]
    void add(int _low, int _high, int push = 1) {
        // disjoint
        if (low > _high || high < _low) return;
        
        // fully contained
        if (low >= _low && high <= _high) {
            stored += push;
            return;
        }

        if (stored) {
            left->add(low, high, stored);
            right->add(low, high, stored);
        }

        left->add(_low, _high, push);
        right->add(_low, _high, push);

        stored = 0;
        return;
    }

    int query(int _low, int _high) {
        if (low > _high || high < _low) return 0;
        if (low == high) return stored;
        return stored + left->query(_low, _high) + right->query(_low, _high);
    }
};

int solve(int tt) {
    // sliding window sum is less than c always
    int n, c;
    cin >> n >> c;
    vi arr(n);
    trav(a, arr) cin >> a;

    int low = 0;
    int high = -1;
    int sm = 0;

    Seg tree(n);
    
    while(low < n) {
        if (high + 1 >= n || sm + arr[high + 1] > c) {
            sm -= arr[low++];
        } else {
            sm += arr[++high];
        }
        sm = max(sm, 0);
        tree.add(low, high);
    }


    rep(i, 0, n) {
        cout << tree.query(i, i) << nl;
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