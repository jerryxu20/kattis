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

vii factors(432);
vi& factor(int n) {
    if (sz(factors[n]) > 0) {
        return factors[n];
    }
    factors[n].resize(432);

    int a = n;
    int d = 2;
    while(d * d <= a) {
        while (a % d == 0) {
            factors[n][d]++;
            a /= d;
        }
        d++;
    }
    if (a > 1) {
        factors[n][a]++;
    }
    if (n > 2) {
        vi &prev = factor(n - 1);
        rep(i, 0, sz(prev)) {
            factors[n][i] += prev[i];
        }
    }
    return factors[n];
}



int solve(int tt) {
    int n, k;
    while(cin >> n >> k) {
        vi &fact = factor(n);
        vi &sub1 = factor(k);
        vi &sub2 = factor(n - k);
        ll ans = 1;
        rep(i, 0, sz(fact)) {
            ans *= ((ll)fact[i] - sub1[i] - sub2[i] + 1);
        }
        cout << ans << nl;
    }
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    int T = 1;
    factors[1] = vi(432);
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}