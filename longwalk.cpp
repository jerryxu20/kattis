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

/**
 Graph with nodes 0 .. 2^n - 1. There is an edge between i and 2i (mod 2^n), i != 0. 
*/

/*
00010
11000

remove trailing 0s from both dudes

00001 (1 to the right)
00011 (3 to the right)

push foward simultaneously

once they are matching, we can we just move backwards by the same amount

1 (4 to the left)
1 (4 to the left)

then we "undo our 4"

00001 (4 to the right)
00001 (4 to the right)

4 + 4 overshoots by 3

(2 + (4-3)*2)

1010
1011

0101 (1 right)
1011 (0 right)

1000 (3 left)
1000 (3 left)

3 + 3 - 1



*/

int n;


bool match(ll a, ll b) {
    while (__builtin_ctzll(b) < __builtin_ctzll(a)) {
        b <<= 1;
        b &= (1LL << n) - 1;
    }
    return a == b;
}

ll calc(ll a, ll b) {
    if (a == b) return 0;
    if (b == 0) return n - __builtin_ctzll(a);
    if (a == 0) return n - __builtin_ctzll(b);

    ll ans = 0;
    while(__builtin_ctzll(a) < __builtin_ctzll(b)) {
        a <<= 1;
        a &= (1LL << n) - 1;
        ans++;
    }
 
    while(!match(a, b)) {
        a <<= 1;
        a &= (1LL << n) - 1;
        ans++;
    }

    if (a == 0) return n - __builtin_ctzll(b);
    // least sig one index
    ll r = __builtin_ctzll(b);
    ll k = __builtin_ctzll(a);
    assert(r <= k);

    ans +=  k - r;

    return ans;
}


int solve(int tt) {
    ll m;

    cin >> n >> m;

    vl walk(m);
    trav(w, walk) cin >> w;

    ll ans = 0;
    rep(i, 1, m) {
        ll a = walk[i - 1];
        ll b = walk[i];
        ans += calc(a, b);
    }
    cout << ans << endl;

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