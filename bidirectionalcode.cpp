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

ll lpal(ll n) { 
    if (n < 10) return n;
    string s = to_string(n);
    int l = sz(s);

    ll ans = 1;
    string base = s;
    
    rep(i,0,l/2) {
        base[l - 1 - i] = base[i];
    }

    if (base <= s) ans = max(ans, stoll(base));

    // try to decrement the middle digits
    if (base[l/2] != '0') {
        base[l/2]--;
        if (l % 2 == 0) base[l/2-1]--;
    }

    if (base <= s) ans = max(ans, stoll(base));

    // consider the all nines with less digits
    ans = max(ans, stoll(string(l - 1, '9')));
    return ans;
}


int solve(int tt) {
    ll n;
    cin >> n;

    vl ans;
    // Greedily choose the largest palindromes
    while(n > 0) {
        ll x = lpal(n);
        assert(x <= n);
        ans.pb(x);
        n -= x;
    }

    cout << sz(ans) << nl;
    trav(a, ans) {
        cout << a << nl;
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