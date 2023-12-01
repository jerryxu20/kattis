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

int solve(int tt) {
    int n, a, b;
    double w, prob = 0;
    cin >> n >> a >> b >> w;
    int goal = max(n/2 + 1 - a, 0);
    int m = n - a - b;
    if (m < goal) {
        cout << "RECOUNT!\n";
        return 0;
    }

    vector<vd> dp(m + 1, vd(m + 1));
    // dp[i]: Chance of getting i total votes
    dp[0][0] = 1; 
    rep(i, 1, m + 1) {
        rep(j, 0, i + 1) {
            // we didn't get this vote
            dp[i][j] += 0.5 * dp[i - 1][j];
            
            // we got this vote
            if (j > 0) dp[i][j] += 0.5 * dp[i - 1][j - 1];
        }
    }

    rep(i, goal, m + 1) {
        prob += dp.back()[i];
    }
    prob *= 100;

    if (prob > w) {
        cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
    } else {
        cout << "PATIENCE, EVERYONE!\n";
    }
    tt++;
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