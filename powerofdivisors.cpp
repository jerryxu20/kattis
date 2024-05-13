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

int divs(ll n) {
    int ans = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans++;
            if (n/i != i) ans++;
        }
    }
    return ans;
}

int solve(int tt) {
    ll x; cin >> x;
    rep(i, 1, 31625) {
        ll f = divs(i);
        ll res = 1;
        rep(_, 0, f) {
            res *= i;
            if (res > x) break;
        }

        if (res == x) {
            cout << i << nl;
            return 0;
        }
    }

    ll s = sqrt(x);
    if (s * s == x) {
        ll ss = sqrt(s);
        if (ss * ss == s && divs(ss) == 4) {
            cout << ss << nl;
            return 0;
        } 
    }

    ll c = cbrt(x);
    if (c * c * c == x && divs(c) == 3) {
        cout << c << nl;
        return 0;
    } 



    if (s * s == x && divs(s) == 2) {
        cout << s << nl;
        return 0;
    }


    cout << -1 << nl;


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