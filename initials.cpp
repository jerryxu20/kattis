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
const int MAXL = 80;
string first[MAXN], last[MAXN];
int dp[MAXN][MAXL];
string catname[MAXN][MAXL];


void lower(string &s) {
    trav(c, s) {
        c = tolower(c);
    }
}

string build(string &f, string &l, int len) {
    string ans;
    len = min(len, sz(f) + sz(l));
    
    int a = min(len - 1, sz(f));
    int b = len - a;

    rep(i, 0, a) {
        ans.pb(f[i]);
    }

    rep(i, 0, b) {
        ans.pb(l[i]);
    }
    
    return ans;
}

int solve(int tt) {
    int n; cin >> n;

    rep(i, 0, n) {
        cin >> last[i] >> first[i];
        lower(first[i]);
        lower(last[i]);
    }

    rep(i, 0, n) {
        rep(j, 0, MAXL) {
            catname[i][j] = build(first[i], last[i], j + 2);
        }
    }

    vi idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](auto &a, auto &b) {
        return catname[a][MAXL - 1] < catname[b][MAXL - 1];
    });
    

    rep(i, 0, MAXL) {
        dp[idx[0]][i] = i;
    }

    rep(i, 1, n) {
        int node = idx[i];
        int prev = idx[i - 1];


        rep(j, 0, MAXL) {
            dp[node][j] = INT_MAX;
            rep(k, 0, MAXL) {
                if (dp[prev][k] != INT_MAX && catname[prev][k] < catname[node][j]) {
                    dp[node][j] = min(dp[prev][k] + j, dp[node][j]);     
                }
            }
        } 
    }
    
    int ans = INT_MAX;
    rep(i, 0, MAXL) {
        ans = min(ans, dp[idx[n - 1]][i]);
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