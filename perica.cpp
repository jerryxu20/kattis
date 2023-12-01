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
const int MX = 100000;

vector<ll> factorial(MX + 1);
vector<ll> inv_fac(MX + 1);

ll fac(ll n) {
    return factorial[n];
}

ll inv(ll n) {
    return inv_fac[n];
}

ll choose(ll n, ll k) {
    if (n < k) return 0;
    ll ans = fac(n) * inv(k);
    ans %= MOD;
    ans *= inv(n - k);
    ans %= MOD;
    return ans;
}

ll power(ll a, ll b) {
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

int solve(int tt) {
    factorial[0] = 1;
    inv_fac[0] = power(1, MOD - 2);
    rep(i, 1, MX + 1) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
        inv_fac[i] = power(factorial[i], MOD - 2); 
    }

    ll n, k;
    cin >> n >> k;
    vl keys(n);

    trav(key, keys) cin >> key;
    sort(all(keys));
    ll ans = 0;


    FORd(i, 0, n) {
        ans += keys[i] * choose(i, k - 1);
        ans %= MOD;
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