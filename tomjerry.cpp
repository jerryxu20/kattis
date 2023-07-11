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

vl fac, inv;
int choose(int n, int k) {
    return (fac[n] * inv[k]) % MOD * inv[n - k] % MOD;
}

ll bexp(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if (b % 2 == 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return res;
}

void prep(int mx) {
    fac.resize(mx + 1);
    inv.resize(mx + 1);
    fac[0] = 1;
    rep(i, 1, mx + 1) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    rep(i, 0, mx + 1) {
        inv[i] = bexp(fac[i], MOD - 2);
    }
}

int solve(int tt) {
    int n, m; cin >> n >> m;
    int N; cin >> N;

    prep(n + m) ;

    vpi cheese(N);
    trav(c, cheese) cin >> c.first >> c.second;
    sort(all(cheese));
    
    vl dp(N);
    // dp[i]: Number of paths from (1, 1) to cheese[i] that don't go any other cheeses
    rep(i, 0, N) {
        auto [x, y] = cheese[i];
        dp[i] = choose(x + y - 2, x - 1);
        rep(j, 0, i) {
            auto [xx, yy] = cheese[j];
            if (xx <= x && yy <= y) {
                int dx = x - xx;
                int dy = y - yy;
                dp[i] -= choose(dx + dy, dx) * dp[j];
                dp[i] %= MOD;
            }
        }
    }
    
    ll ans = 0;
    rep(i, 0, N) {
        int dx = n - cheese[i].first;
        int dy = m - cheese[i].second;
        ans += choose(dx + dy, dx) * dp[i];
        ans %= MOD; 
    }
    cout << (ans + MOD) % MOD << nl;
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