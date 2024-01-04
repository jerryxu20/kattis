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

int solve() {
    int n; cin >> n;
    vi coins(n);
    trav(a, coins) cin >> a;

    // go up to mx amount * 2, so all mods of mx coin are considered
    int mx = coins.back() * 2;


    // What is the number of moves in the greedy way
    vi greedy(mx + 1);
    int idx = 0;
    rep(i, 1, mx + 1) {
        if (idx + 1 < n && coins[idx + 1] <= i) {
            idx++;
        }

        greedy[i] = greedy[i % coins[idx]] + i/coins[idx];
    }

    // What is the optimal way to do each amount
    vi dp(mx + 1, INT_MAX);
    dp[0] = 0;

    rep(i, 0, mx + 1) {
        trav(c, coins) {
            if (i - c < 0) break;
            dp[i] = min(dp[i], 1 + dp[i - c]);
        }
    }

    // Check answer using both methods
    rep(i, 0, mx + 1) {
        if (dp[i] != greedy[i]) {
            cout << "non-canonical\n";
            return 0;
        }
    }

    cout << "canonical\n";
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve()
    return 0;
}