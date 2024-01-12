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
const int MAX = 1e6 + 1;

vi primes;
int isprime[MAX];

void sieve() {
    for (int i = 2; i <= MAX; i++) {
        if (isprime[i] == 0) {
            primes.pb(i);
            for (int j = 2 * i; j <= MAX; j += i) {
                isprime[j] = i;
            }
        }
    }
}

vpi factor(ll x, ll y) {
    vpi ans;
    for (auto &p: primes) {
        int run = 0;
        while(x % p == 0) {
            x /= p;
            run++;
        }
        while(y % p == 0) {
            y /= p;
            run++;
        }
        if (run) ans.pb({p, run});
    }
    return ans;
}

int solve(int tt) {
    sieve();
    ll a, c; cin >> a >> c;

    vpi facs = factor(a, c);
    
    ll divs = 1;
    for (auto &[_, cnt]: facs) {
        divs *= (cnt + 1);
    }

    ll ans = (divs + 1)/2 * 2;
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