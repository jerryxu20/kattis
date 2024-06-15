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
const int MAXK = 11;
const int MAXN = 1e5 + 2;

ll A[MAXN], B[MAXN];
ll dp[2 * MAXN][MAXK][MAXK];
ll valid[2 * MAXN][MAXK][MAXK];
int n, k;


ll f(int moves, int a, int b, int ab, int bb, int player) {
    
    // moves = a + b + banneda + banned b
    if (valid[moves][a][b]) return dp[moves][a][b];
    ll &ans = dp[moves][a][b];
    int i = a + bb;
    int j = b + ab;

    if (moves == 2 * n) return 0;

    if (player == 0) {
        ans = LLONG_MIN;
        // take
        if (i < n && a < k) {
            ans = max(ans, A[i] + f(moves + 1, a + 1, b, ab, bb, player ^ 1));
        }

        // ban
        if (j < n) {
            ans = max(ans, f(moves + 1, a, b, ab + 1, bb, player ^ 1));
        }
    } else {
        ans = LLONG_MAX;
        if (j < n && b < k) {
            ans = min(ans, -B[j] + f(moves + 1, a, b + 1, ab, bb, player ^ 1));
        }

        if (i < n) {
            ans = min(ans, f(moves + 1, a, b, ab, bb + 1, player ^ 1));
        }
    }

    valid[moves][a][b] = 1;
    return ans;
}

int solve(int tt) {
    cin >> n >> k;

    rep(i, 0, n) cin >> A[i];
    rep(i, 0, n) cin >> B[i];

    sort(A, A + n, greater<ll>());
    sort(B, B + n, greater<ll>());

    cout << f(0, 0, 0, 0, 0, 0) << endl;
    

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