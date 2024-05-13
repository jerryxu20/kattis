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
typedef tuple<int,int,int,int,int> ti;
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
const int N = 1 << 0;
const int E = 1 << 1;
const int S = 1 << 2;
const int W = 1 << 3;
constexpr int MASK = (1 << 4) - 1;
int dis[20][20][16][400];


int rotate(int state, bool clock = true) { 
    if (clock) {
        // N -> E, E -> S, S - > W, W -> N
        int west = state & W;
        state <<= 1;

        if (west) state += N;
        return state & MASK;
    }

    int north = state & N;
    state >>= 1;
    if (north) state += W;
    return state & MASK;

}

int ord(char c) {
    if (c == 'N') return N;
    if (c == 'E') return E;
    if (c == 'S') return S;
    if (c == 'W') return W;
    return 0;
}

int state(string &s) {
    int ans = 0;
    trav(x, s) {
        ans += ord(x);
    }    
    return ans;
}

vpi delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vpi options(int state) {
    vpi ans;
    rep(_, 0, 4) {
        ans.pb({state, 0});
        state = rotate(state);
    }

    ans[0].second = 0;
    ans[1].second = 1;
    ans[2].second = 2;
    ans[3].second = 1;
    return ans;
}

bool compat(int node, int nxt, const pi &d) {
    // moving down
    if (d == mp(1, 0)) {
        return (node & S) && (nxt & N);
    }
    // moving up
    if (d == mp(-1, 0)) {
        return (node & N) && (nxt & S);
    }

    // moving east
    if (d == mp(0, 1)) {
        return (node & E) && (nxt & W); 
    }
    // moving west
    if (d == mp(0, -1)) {
        return (node & W) && (nxt & E);
    }
    assert(false);
    return false;
}

int solve(int tt) {
    int n, m; cin >> n >> m;
    
    pi s, t;
    cin >> s.first >> s.second;
    cin >> t.first >> t.second;

    s.first--; s.second--;
    t.first--; t.second--;

    vii grid(n, vi(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            string e; cin >> e;
            grid[i][j] = state(e);
            int state = grid[i][j];
            // if (state & N) {
            //     cout << "N";
            // }
            // if (state & E) {
            //     cout << "E";
            // }
            // if (state & S) {
            //     cout << "S";
            // }
            // if (state & W) {
            //     cout << "W";
            // }
            // cout << " ";
        }
        // cout << nl;
    }
    // cout << sizeof(dis) << endl;
    // fill_n(&dis[0][0][0][0], sizeof(dis), INT_MAX);
    // fill_n(&dis, sizeof(dis), INT_MAX);
    // cout << "dick" << endl;

    rep(i, 0, 20) {
        rep(j, 0, 20) {
            rep(k, 0, 16) {
                rep(l, 0, 400) {
                    dis[i][j][k][l] = INT_MAX;
                }
            }
        }
    }

    // cout << "dick" << endl;


    dis[s.first][s.second][grid[s.first][s.second]][0] = 0;
    PQG<ti> pq;
    pq.push({0, s.first, s.second, grid[s.first][s.second], 0});

    while(sz(pq)) {
        auto [d, i, j, state, saved] = pq.top();
        pq.pop();

        if (mp(i, j) == t) {
            cout << d << nl;
            return 0;
        }
        vpi cur = options(state);

        for (auto &[a, b]: delta) {
            int ii = i + a;
            int jj = j + b;
            if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;

            vpi adj = options(grid[ii][jj]);

            for (auto &[node, A]: cur) {
                for (auto &[nxt, B]: adj) {
                    if (dis[ii][jj][nxt][saved] <= d + 1) continue;
                    if (A + B == 2 && saved == 0) continue;
                    if (!compat(node, nxt, {a, b})) continue;
                    
                    int nsaved = saved - A - B + 1;
                    dis[ii][jj][nxt][saved] = d + 1; 
                    pq.push({d + 1, ii, jj, nxt, nsaved});
                }
            }
        }        
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