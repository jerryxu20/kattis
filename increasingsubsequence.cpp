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
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';
int n;
int solve(int tt) {
    cin >> n;
    if (n == 0) return 1;
    vi nums(n);
    trav(num, nums) cin >> num;
    vii dp(n, vi(3));
    int start = 0;
    rep(i, 0, n) {
        dp[i] = {1, i, -nums[i]};
        rep(j, 0, i) {
            if (nums[j] >= nums[i]) continue;
            vi nxt = {dp[j][0] + 1, j, -nums[i]};
            dp[i] = max(nxt,dp[i]);
        }   
        if (dp[i][0] > dp[start][0]) start = i;
        if (dp[i][0] == dp[start][0] && nums[i] < nums[start]) start = i;
    }
    vi ans;
    int len = dp[start][0];
    while(len--) {
        ans.pb(nums[start]);
        start = dp[start][1];
    }
    reverse(all(ans));
    cout << sz(ans) << " ";
    trav(a, ans) {
        cout << a << " ";
    }
    cout << nl;

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1;; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}