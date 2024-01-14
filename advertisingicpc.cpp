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

const int MOD = 998244353;
const char nl = '\n';

string grid[8];
ll pref[65], pow3[70];
int dp[8][8][60000];
int n, m;
ll total = 0;
string choice = "IPC";

/*
dp[i][j][x]: number of ways to color up to grid[i][j] if I go row by row, such that there are no
ICPCs. x is what the last m + 2 chars are. the last char is what grid[i][j]
will take on. 
*/

int id(int i, int j) {
    return j + i * m;
}

pi coord(int id) {
    int j = id % m;
    int i = id/m;
    return {i, j};
}

string decode(int x, int len) {
    string ans = "";
    rep(_, 0, len) {
        ans.pb(choice[x%3]);
        x/=3;
    }
    reverse(all(ans));
    return ans;
}

int dfs(int i, int j, int cur) {
    int idx = id(i, j);
    cur %= pow3[idx + 2];

    int &ans = dp[i][j][cur];
    if (ans != -1) return ans;
    ans = 0;

    string s = decode(cur, min(idx + 1, m + 2));
    if (grid[i][j] != '?' && s.back() != grid[i][j]) {
        ans = 0;
        return ans;
    }

    if (idx == 0) {
        ans = 1;
        return ans;
    }

    // check for icpc
    bool has = false;
    if (sz(s) == m + 2 && j != 0) {
        if (s[0] == 'I' && s[1] == 'C' && s[sz(s) - 2] == 'P' && s[sz(s) - 1] == 'C') {
            has = true;
        } 
    }

    auto [ii, jj] = coord(idx - 1);
    int ways = 0;
    if (idx < m + 2) {
        ways = dfs(ii, jj, cur/3);
    } else {
        rep(c, 0, 3) {
            int nxt = cur/3 + c * pow3[m + 1];
            ways += dfs(ii, jj, nxt);
            if (ways >= MOD) ways -= MOD;
        }
    }

    if (has) {
        int qmarks = pref[n*m] - pref[idx + 1];
        total += ways * pow3[qmarks];
        total %= MOD;
    } else {
        ans += ways;
        if (ans >= MOD) ans -= MOD;
    }

    return ans;
}


int solve(int tt) {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> grid[i];
    }

    pow3[0] = 1;
    rep(i, 1, 70) {
        pow3[i] = pow3[i - 1] * 3;
        pow3[i] %= MOD;
    }


    rep(i, 0, n) {
        rep(j, 0, m) {
            pref[id(i, j) + 1] = pref[id(i, j)] + int(grid[i][j] == '?');
        }
    }
    

    rep(i, 0, pow3[m + 2]) {
        dfs(n - 1, m - 1, i);
    }

    cout << total << endl;

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