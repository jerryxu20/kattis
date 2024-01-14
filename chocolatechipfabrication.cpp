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
    int n, m;
    cin >> n >> m;
    vs grid(n);
    trav(row, grid) cin >> row;


    queue<pi> q;
    vpi delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] != 'X') continue;
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                q.push(mp(i, j));
                grid[i][j] = ' ';
                continue;
            }
            for (auto &[a, b]: delta) {
                if (grid[i + a][j + b] == '-') {
                    q.push(mp(i, j));
                    grid[i][j] = ' ';
                    break;
                }
            }
        }
    }


    int ans = 0;
    while(true) {
        int z = sz(q);
        if (z == 0) break;

        while(z--) {
            auto [i, j] = q.front();
            // cout << i << ' ' << j << endl;
            q.pop();

            for (auto &[a, b]: delta) {
                int ii = i + a;
                int jj = j + b;
                if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
                if (grid[ii][jj] == 'X') {
                    grid[ii][jj] = ' ';
                    q.push(mp(ii, jj));
                }
            }
        }
        // cout << endl;
        ans++;
    }
    cout << ans << endl;



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