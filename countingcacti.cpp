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
int n, m;

vpi delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int i, int j, vs &grid) {
    int ans = 0;
    if (grid[i][j] == '*') ans++;
    grid[i][j] = '1';
    for (auto &[a, b]: delta) {
        int ii = i + a;
        int jj = j + b;
        if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
        if (grid[ii][jj] == ' ' || grid[ii][jj] == '*') ans += dfs(ii, jj, grid);
    }

    return ans;
}

int solve(int tt) {
    cin >> n >> m;
    vs grid(n);
    string s; getline(cin, s);
    trav(row, grid) getline(cin, row);

    int cnt = 0;
    int mx = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] == ' ' || grid[i][j] == '*') {
                mx = max(mx, dfs(i, j, grid));
                cnt++;
            }
        } 
    }
    cout << cnt << " " << mx << endl;


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