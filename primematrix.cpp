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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

vi primes;
void sieve() {
    vi is_prime(100000, true);
    for (int i = 2; i< sz(is_prime); i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j < sz(is_prime); j += i) {
                is_prime[j] = false;
            }
            primes.pb(i);
        }
    }
    return;
}

int solve(int tt) {
    int n, b;
    cin >> n >> b;
    if (b < n) {
        cout << "impossible\n";
        return 0;
    }
    int sm = n * (n + 1) / 2;
    
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);

    int prime = *lower_bound(all(primes), sm);
    for (int i = n + 1; i <= b; i++) {
        if (sm == prime) break;
        int target = sm + i - prime;
        auto it = st.lower_bound(target);
        sm -= *it;
        st.erase(it);
        st.insert(i);
        sm += i;
    }
    assert(n == b || prime == sm);
    if (prime != sm) {
        cout << "impossible\n";
        return 0;
    }
    vi row(all(st));
    rep(i, 0, n) {
        int j = i;
        rep(k, 0, n) {
            cout << row[j] << " ";
            j++;
            j %= n;
        }
        cout << nl;
    }
    
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    sieve();
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}