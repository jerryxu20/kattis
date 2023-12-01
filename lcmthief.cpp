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

map<ll, ll> factor(ll a) {
    ll div = 2;
    map<ll, ll> ans;
    while(div * div <= a) {
        while(a % div == 0) {
            a /= div;
            ans[div]++;
        }
        div++;
    }
    if (a > 1) ans[a]++;
    return ans;
}

ll bexp(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    return bexp(a, b/2) * bexp(a, b/2) * bexp(a, b%2);
}

int solve(int tt) {
    ll n; cin >> n;
    vl arr(n);
    trav(a, arr) cin >> a;
    sort(all(arr));

    vector<map<ll, ll>> factors;
    map<ll, pi> lcm;
    trav(a, arr) {
        map<ll, ll> facs = factor(a);
        factors.push_back(facs);

        for (auto [f, cnt]: facs) {
            if (cnt > lcm[f].second) lcm[f].second = cnt;
            if (lcm[f].first < lcm[f].second) swap(lcm[f].first, lcm[f].second);
        }
    }
    ll best = LLONG_MAX;
    ll ans = 0;
    int i = 0;
    trav(facs, factors) {
        ll cand = 1;
        for (auto &[f, cnt]: facs) {
            if (cnt < lcm[f].first) continue;
            cand *= bexp(f, cnt - lcm[f].second);
        }

        if (cand < best) {
            ans = arr[i];
            best = cand;
        }   
        i++;
    }
    cout << ans << nl;

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