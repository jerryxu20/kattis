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

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}

int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(all(btoa), -1);
}

int solve(int tt) {
    int n, m, K;
    cin >> n >> m >> K;
    vii dp(n, vi(n, INT_MAX));
    int a, b, c;
    rep(_, 0, m) {
        cin >> a >> b >> c;
        a--; b--;
        dp[a][b] = c;
    }
    rep(i, 0, n) {
        dp[i][i] = 0;
    }
    rep(k, 0, n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                if (dp[i][k] == INT_MAX || dp[k][j] == INT_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // edge a->b means I can go from trip a to trip b
    vii trip_adj(K);
    vector<ti> trip(K);

    for (auto &[a, b, t]: trip) {
        cin >> a >> b >> t;
        a--; b--;
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (i == j) continue;
            auto &[a, b, t1] = trip[i];
            auto &[c, d, t2] = trip[j];
            // pickup + dropoff + reach next destination
            int time = t1 + dp[a][b] + dp[b][c];
            if (time <= t2) {
                trip_adj[i].pb(j);
                // cout << "edge " << i << " " << j << endl;
            }
        }
    }

    vi match(K, -1);
    int cnt = dfsMatching(trip_adj, match);
    cout << max(K - cnt, 1) << nl;



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