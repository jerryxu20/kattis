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
    string s;
    vs grid;
    bool last = true;
    while(getline(cin, s)) {
        if (sz(s) == 0) {
            last = false;
            break;
        }
        grid.pb(s);
    }

    int n = sz(grid);
    int m = sz(grid[0]);

    vs line(m, string(n, ' '));
    rep(i, 0, n) {
        rep(j, 0, m) {
            line[j][i] = grid[i][j];
        }
    }

    vi stars;
    trav(ss, line) {
        int x = find(all(ss), '*') - ss.begin();
        stars.pb(x);
    }

    sort(all(stars));

    int i = 0;
    trav(loc, stars) {
        line[i++] = string(loc, '.') + '*' + string(n - loc - 1, '.');
    }
    reverse(all(line));

    rep(i, 0, n) {
        rep(j, 0, m) {
            cout << line[j][i];
        }
        cout << nl;
    }
    cout << nl;
    if (last) return 1;

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    return 0;
}