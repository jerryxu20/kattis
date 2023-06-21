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

const int MOD = 1001113;
const char nl = '\n';

int dp[101][100][100];
int sm[101][100];

int solve(int tt) {
    dp[0][0][0] = 1;
    sm[0][0] = 1;
    rep(i, 1, 101) {
        rep(j, 0, i) {
            if (j == 0) {
                rep(k, 0, i) {
                    dp[i][j][k] = sm[i - 1][k];
                    sm[i][k] = sm[i - 1][k];
                }
                continue;
            }
            rep(k, 0, i) {
                dp[i][j][k] = dp[i][j - 1][k] - dp[i - 1][j - 1][k];
                if (k > 0) {
                    dp[i][j][k] += dp[i - 1][j - 1][k - 1];
                }
                dp[i][j][k] += MOD;
                dp[i][j][k] %= MOD;
                sm[i][k] += dp[i][j][k];
                sm[i][k] %= MOD;
            }
        }
    }
    int q, n, k;
    cin >> q;
    while(q--) {
        cin >> tt >> n >> k;
        cout << tt << " " << sm[n][k] << nl;        
    }
    
    
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