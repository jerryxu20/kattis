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
int n, m, r;

int id(int i, int j) {
    return i * m + j;
}

struct UF {
    vi rank, id;
    UF(int n) {
        rank.resize(n, 1);
        id.resize(n);
        iota(all(id), 0);
    }

    int find(int a) {
        if (a == id[a]) return a;
        id[a] = find(id[a]);
        return id[a];
    }

    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[b] > rank[a]) swap(a, b);
        rank[a] += rank[b];
        id[b] = a;
        return true;
    }  
};

int solve(int tt) {
    cin >> n >> m >> r;
    vs grid(n);
    trav(s, grid) cin >> s;
    
    vector<tuple<int, int, int, int>> edges;

    vector<int> above(m, -1);
    int prev;
    int comp = 0;
    rep(i, 0, n) {
        prev = -1;
        rep(j, 0, m) {
            if (grid[i][j] != '*') continue;
            comp++;
            if (prev != -1) {
                edges.push_back({i, j, i, prev});
            }
            
            if (above[j] != -1) {
                edges.push_back({i, j, above[j], j});
            }

            above[j] = i;
            prev = j;
        }
    }

    UF uf(n * m);
    
    while(comp > r) {
        assert(sz(edges));
        auto [i, j, ii, jj] = edges.back();
        edges.pop_back();

        if (uf.join(id(i, j), id(ii, jj))) {
            comp--;

            for (int a = min(i, ii) + 1; a < max(i, ii); a++) {
                assert(grid[a][j] == '.' || grid[a][j] == '-');
                if (grid[a][j] == '.') {
                    grid[a][j] = '|';
                } else {
                    grid[a][j] = '+';
                }
            }

            for (int b = min(j, jj) + 1; b < max(j, jj); b++) {
                assert(grid[i][b] == '.' || grid[i][b] == '|');
                if (grid[i][b] == '.') {
                    grid[i][b] = '-';
                } else {
                    grid[i][b] = '+';
                }
            }
            
        }
    }

    trav(s, grid) {
        trav(c, s) {
            if (c == '.') c = ' ';
        }
        cout << s << nl;
    }


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