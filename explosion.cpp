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

map<pair<vi, vi>, double> dp;

double f(vi good, vi bad, int n) {
    if (sz(bad) == 0) return 1;
    if (n == 0) return 0;
    pair<vi, vi> state = {good, bad};
    if (dp.count(state)) return dp[state];

    double ans = 0;
    int total = sz(good) + sz(bad);
    rep(i, 0, sz(good)) {
        vi ngood = good;
        ngood[i]--;
        sort(all(ngood), greater<int>());
        while(sz(ngood) && ngood.back() == 0) ngood.pop_back();
        ans += 1.0/total * f(ngood, bad, n - 1); 
    }

    rep(i, 0, sz(bad)) {
        vi nbad = bad;
        nbad[i]--;
        sort(all(nbad), greater<int>());
        while(sz(nbad) && nbad.back() == 0) nbad.pop_back();
        ans += 1.0/total * f(good, nbad, n - 1);
    }
    dp[state] = ans;
    return ans;
}

int solve(int tt) {
    int n, m, d;
    cin >> n >> m >> d;

    vi good(n), bad(m);

    trav(g, good) cin >> g;
    trav(b, bad)  cin >> b;

    cout << setprecision(20) << f(good, bad, d) << endl;
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