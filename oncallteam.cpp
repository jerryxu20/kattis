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
int N = 0;
int n, m;
bool valid(int mask, vii &adj) {
    vi atob(N);
    rep(i, 0, m) {
        if (mask & (1 << i)) {
            trav(nxt, adj[i]) {
                atob[nxt] = 1;
            }
        }
    }

    if (count(all(atob), 1) >= __builtin_popcount(mask)) return true;
    return false;
}


int solve(int tt) {
    cin >> n >> m;
    vi cnt(m);
    vii adj(m);

    int idx = 0;
    rep(_, 0, n) {
        string s; cin >> s;
        int helps = 0;
        rep(i, 0, m) {
            if (cnt[i] < m && s[i] == '1') helps = 1;
        }
        if (helps == 0) continue;
        rep(i, 0, m) {
            if (s[i] == '1') {
                cnt[i]++;
                adj[i].pb(N);
            }
        }
        N++;
    }

    int ans = m;
    rep(mask, 0, 1 << m) {
        if (!valid(mask, adj)) {
            ans = min(ans, __builtin_popcount(mask) - 1);
        }
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