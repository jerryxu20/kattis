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
const int MAXN = 3e5;
int tasks[MAXN];
int dp[MAXN][4][10];
int n;


int dfs(int idx, int cur, int avail) {
    if (idx == n) return 0;
    if (dp[idx][cur][avail] != -1) return dp[idx][cur][avail];

    int &ans = dp[idx][cur][avail];
    int need = tasks[idx];
    ans = 0;
    if (cur == need) {
        ans = 1 + dfs(idx + 1, cur, avail);
        return ans;
    }

    ans = max(ans, dfs(idx + 1, cur, avail));

    if (avail & (1 << need)) {
        ans = max(ans, 1 + dfs(idx + 1, need, avail & ~(1 << need)));
    }
    return ans;
}


int solve(int tt) {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    rep(i, 0, n) cin >> tasks[i];
    cout << dfs(0, 3, (1 << 3) - 1) << nl;

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