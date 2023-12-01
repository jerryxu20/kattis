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

map<string, int> dp;
vector<pi> winning;

int mex(vi &arr) {
    set<int> st(all(arr));
    for (int i = 0; ;i++) {
        if (!st.count(i)) return i;
    }
    assert(false);
    return -1;
}

int dfs(string s) {
    if (dp.count(s)) return dp[s];
    vi cand;
    string left, right;
    int nxt;
    rep(i, 1, sz(s)) {
        if (s[i] == s[i - 1]) continue;
        // there are two moves at this position
        // s[i] takes s[i - 1]
        left = s.substr(0, i - 1);
        right = s[i - 1] + s.substr(i + 1);
        nxt = dfs(left) ^ dfs(right);
        
        cand.pb(nxt);

        left = s.substr(0, i - 1) + s[i];
        right = s.substr(i + 1);
        nxt = dfs(left) ^ dfs(right);

        cand.pb(nxt);
    }

    int ans = mex(cand);
    dp[s] = ans;
    return ans;
} 

pair<vs, vi> split(string &s) {
    string cur = "";
    vs ans;
    vi idx;
    int low = 0;
    s.pb('.');
    rep(i, 0, sz(s)) {
        if (s[i] == '.') {
            if (sz(cur)) {
                ans.pb(cur);
                idx.pb(low);
            }
            low = i + 1;
            cur = "";
            continue;
        }
        cur += s[i];
    }

    return {ans, idx};
}

int solve(int tt) {
    int n; cin >> n;
    string s; cin >> s;
    // split this
    auto [games, idx] = split(s);
    vi grundy(sz(games));
    int res = 0;
    rep(i, 0, sz(games)) {
        grundy[i] ^= dfs(games[i]);
        res ^= grundy[i];
    }
    if (res == 0) {
        cout << 0 << nl;
        return 0;
    }
    vpi ans;
    rep(j, 0, sz(games)) {
        string g = games[j];
        string left, right;
        int nxt;
        rep(i, 1, sz(g)) {
            if (g[i] == g[i - 1]) continue;
            // there are two moves at this position
            // s[i] takes s[i - 1]
            left = g.substr(0, i - 1);
            right = g[i - 1] + g.substr(i + 1);
            nxt = dfs(left) ^ dfs(right);
            if ((res ^ grundy[j] ^ nxt) == 0) ans.pb({i - 1 + idx[j], i + idx[j]});

            left = g.substr(0, i - 1) + g[i];
            right = g.substr(i + 1);
            nxt = dfs(left) ^ dfs(right);

            if ((res ^ grundy[j] ^ nxt) == 0) ans.pb({i + idx[j], i - 1 + idx[j]});
        }
    }
    cout << sz(ans) << endl;
    for (auto &[a, b]: ans) {
        cout << a + 1 << " " << b + 1 << endl;
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