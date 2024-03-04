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
vs grid(4);
vs cur(4, string(4, ' '));

vpi delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

set<vs> valid;

void dfs(int i, int j, char c) {
    // invalid square
    if (i < 0 || j < 0 || i >= 4 || j >= 4) return;
    if (cur[i][j] == c) return;

    char x = grid[i][j];
    if (x == 'W' || x == tolower(c)) {
        cur[i][j] = c;
        for (auto &[a, b]: delta) {
            int ii = i + a;
            int jj = j + b;
            dfs(ii, jj, c);
        }
        cur[i][j] = ' ';
    }
    
    if (x == c) {
        cur[i][j] = c;
        valid.insert(cur);
        cur[i][j] = ' ';
    }
}

void check() {
    for (char c: {'R', 'G', 'B', 'Y'}) {
        vs mask = grid;
        trav(row, mask) {
            trav(x, row) {
                if (x != c) x = ' ';
            }
        }
        
        if (!valid.count(mask)) return;
    }

    cout << "solvable\n";
    exit(0);
}

void backtrack(int i, int j) {
    if (i == 3 && j == 4) {
        check();
        return;
    }

    if (j == 4) {
        j = 0;
        i++;
    }

    if (grid[i][j] == 'W') {
        for (char c: {'R', 'G', 'B', 'Y'}) {
            grid[i][j] = c;
            backtrack(i, j + 1);
        }
        grid[i][j] = 'W';
    } else {
        backtrack(i, j + 1);
    }

}


int solve(int tt) {
    trav(s, grid) cin >> s;
    valid.insert(cur);

    for (char c: {'R', 'G', 'B', 'Y'}) {
        int i = -1;
        int j = -1;
        rep(ii, 0, 4) {
            rep(jj, 0, 4) {
                if (grid[ii][jj] == c) {
                    grid[ii][jj] = tolower(c);
                    i = ii;
                    j = jj;
                    break;
                }
            }
            if (i != -1) break;
        }
        if (i != -1) {
            dfs(i, j, c);
            grid[i][j] = c;            
        }
    }

    backtrack(0, 0);
    cout << "not solvable\n";

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