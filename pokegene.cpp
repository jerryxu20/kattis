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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
    vector<string> team;
    int n;
	RMQ(const vector<T>& V, vector<string> &team) : jmp(1, V) {
        this->team = team;
        n = sz(V);
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
        if (a == b) return sz(team[a]);
        if (a < 0) return 0;
        if (b > n) return 0;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int longestpref(string &s, string &t) {
    int ans = 0;
    rep(i, 0, min(sz(s), sz(t))) {
        if (s[i] != t[i]) break;
        ans++;
    }
    return ans;
}


int solve(int tt) {
    int n, q; cin >> n >> q;
    vs mons(n);
    trav(s, mons) cin >> s;

    vi idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&] (auto &a, auto &b) {
        return mons[a] < mons[b];
    });

    vi mapping(n);
    rep(i, 0, n) {
        mapping[idx[i]] = i;
    }

    vi delta;
    rep(i, 1, n) {
        delta.pb(longestpref(mons[idx[i]], mons[idx[i - 1]]));
    }

    sort(all(mons));
    RMQ<int> mn(delta, mons);


    while(q--) {
        int k, l; cin >> k >> l;

        vi team(k);
        rep(i, 0, k) {
            int idx; cin >> idx;
            team[i] = mapping[idx - 1];
        }

        sort(all(team));
        int ans = 0;
        int prev = -1;
        rep(i, 0, k) {
            if (i + l - 1 >= k) break;
            ans += mn.query(team[i], team[i + l - 1]);
            int sub = 0;
            if (i > 0) {
                sub = max(sub, mn.query(team[i - 1], team[i + l - 1]));
            }
            if (i + l < k) {
                sub = max(sub, mn.query(team[i], team[i + l]));
            }
            ans -= sub;
        }

        cout << ans << nl;
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