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
const int MAXN = 100;

int adj[MAXN];
int tin[MAXN];
int last[MAXN];
int cycle_len[MAXN];
int cycle_id[MAXN];

int timer = 0;
int tc = 1;
int N = 0;

void dfs(int node) {
    tin[node] = timer++;
    last[node] = tc;
    cycle_id[node] = N;
    if (last[adj[node]] == tc) {
        cycle_len[N] = tin[node] - tin[adj[node]] + 1;
        N++;
        return;         
    }
    dfs(adj[node]);
}

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

int solve(int tt) {
    int n; cin >> n;
    timer = 0;
    N = 0;

    vi s(n), t(n);
    trav(a, s) {
        cin >> a;
        a--;
    }
    trav(a, t) {
        cin >> a;
        a--;
    }

    rep(i, 0, MAXN) {
        cin >> adj[i];
        adj[i]--;
    }
    rep(i, 0, MAXN) {
        if (last[i] != tc) dfs(i);
    }

    // ans = x + n len -> (ans == x) mod len
    vpi cong;

    rep(i, 0, n) {
        int a = s[i];
        int b = t[i];

        assert(cycle_id[a] == cycle_id[b]);

        int len = cycle_len[cycle_id[a]];
        int atob = tin[b] - tin[a];
        if (atob < 0) atob += len;
        cong.pb(mp(atob, len));
    }

    int a = cong[0].first;
    int m = cong[0].second;

    rep(i, 1, n) {
        a = crt(a, m, cong[i].first, cong[i].second);
        m = lcm(m, cong[i].second);
    }

    cout << a << nl;
    
    tt++;
    tc++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}