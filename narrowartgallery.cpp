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
int dp[200][3][200];
int n, k;
// what is the max cost to reach last row from row given we need to block of x rows
int f(int i, int prev, int x, vii &grid) {
    if (i == n) {
        if (x != 0) return 1e6;
        return 0;
    }

    int &ans = dp[i][prev][x];
    if (ans != -1) return ans;

    ans = INT_MAX;
    // [free, blocked], I can consider blocking right 
    if (prev == 1 || prev == 0) {
        ans = min(ans, grid[i][1] + f(i + 1, 1, x - 1, grid));
    }

    // [blocked, free], I can consider blocking left
    if (prev == 2 || prev == 0) {
        ans = min(ans, grid[i][0] + f(i + 1, 2, x - 1, grid));
    }
    // block nothing 
    ans = min(ans, f(i + 1, 0, x, grid));

    return ans;
    
}


int solve(int tt) {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    if (n == 0 && k == 0) return 1;

    
    vii grid(n, vi(2));
    int sm = 0;
    trav(row, grid) {
        trav(x, row) {
            cin >> x;
            sm += x;
        }
    }

    cout << sm - f(0, 0, k, grid) << endl;


    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}