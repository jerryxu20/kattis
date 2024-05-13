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
const int MAXN = 1000;
int n, k;

int cost[26][26];
ll dp[MAXN][MAXN];


ll f(int prev, int len) {
    if (k % 2 == 1 && len <= 0) return 0;
    if (k % 2 == 0 && len == 0) {
        if (cost[prev][prev]) return cost[prev][prev];
        return 1e9;
    }

    if (prev == -1) {
        ll ans = 1e9;
        rep(i, 0, 26) {
            rep(j, 0, 26) {
                if (cost[i][j] && cost[j][i]) {
                    ans = min(ans, cost[i][j] + cost[j][i] + f(j, len - 4));
                }
            }
        }
        return ans;
    }

    ll &ans = dp[prev][len];
    if (ans != -1) return ans;
    
    ans = 1e9;
    rep(j, 0, 26) {
        if (cost[prev][j] && cost[j][prev]) {
            ans = min(ans, cost[prev][j] + cost[j][prev] + f(j, len - 2));
        }
    }

    return ans;
}

int solve(int tt) {
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));


    rep(i, 0, n) {
        string s;
        int c;
        cin >> s >> c;
        cost[s[0] - 'a'][s[1] - 'a'] = c;

    }


    ll ans = 1e9;
    if (k == 2) {
        rep(i, 0, 26) {
            if (cost[i][i]) ans = min(ans, (ll)cost[i][i]);
        }
    } else {
        ans = f(-1, k);
    }
    if (ans == 1e9) ans = -1;
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