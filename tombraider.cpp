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
const int MAXN = 500;
constexpr int MX = MAXN * MAXN;
const int BACK = -2;
const int OBS = -3;

const int RIGHT = 0;
const int LEFT = 1;
const int DOWN = 2;
const int UP = 3;

const int HOR = 0;
const int VERT = 1;

int dp[MAXN][MAXN][4];
int id[MAXN][MAXN];
string grid[MAXN];
int hit[MAXN][MAXN][4];
int seen[MX];
int start[MX];

int N = 0;
int n, m;
int TIME = 0;
vpi delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dir_id(const pi& dir) {
    if (dir == mp(0, 1))  return 0;
    if (dir == mp(0, -1)) return 1;
    if (dir == mp(1, 0))  return 2;
    if (dir == mp(-1, 0)) return 3;
    assert(false);
    return -1;
}   

int change_dir(char c, int dir) {
    if (c == '/' && dir == UP) return RIGHT;
    if (c == '/' && dir == DOWN) return LEFT;
    if (c == '/' && dir == RIGHT) return UP;
    if (c == '/' && dir == LEFT) return DOWN;

    if (c == '\\' && dir == UP) return LEFT;
    if (c == '\\' && dir == DOWN) return RIGHT;
    if (c == '\\' && dir == RIGHT) return DOWN;
    if (c == '\\' && dir == LEFT) return UP;

    return dir;
}

int dfs(int i, int j, int dir) {
    if (i == -1 || j == -1 || i == n || j == m) return BACK;
    
    if (dp[i][j][dir] != -1) return dp[i][j][dir];
    if (grid[i][j] == '#') {
        return OBS;
    }
    if (id[i][j] != -1) {
        return id[i][j];
    }

    int ndir = change_dir(grid[i][j], dir);

    if (ndir != dir) {
        hit[i][j][dir] = 1;
    }

    auto &[a, b] = delta[ndir];
    int ii = i + a;
    int jj = j + b;

    dp[i][j][dir] = dfs(ii, jj, ndir);
    if (ii >= 0 && jj >= 0 && ii < n && jj < m) hit[i][j][dir] += hit[ii][jj][ndir];
    return dp[i][j][dir];
}

pair<pi, pi> config(int d1, int d2, int i, int j) {
    int ii, jj;

    auto &[a, b] = delta[d1];
    ii = i + a;
    jj = j + b;
    
    int x = dfs(ii, jj, d1);
    int hx = 0;
    if (ii >= 0 && jj >= 0 && ii < n && jj < m) hx = hit[ii][jj][d1];


    auto &[c, d] = delta[d2];
    ii = i + c;
    jj = j + d;
    
    int y = dfs(ii, jj, d2);
    int hy = 0;
    if (ii >= 0 && jj >= 0 && ii < n && jj < m) hy= hit[ii][jj][d2];
    return {{x, hx}, {y, hy}};
}

int bfs(vector<vpi> &hor, vector<vpi> &vert, int s, int init) {
    vi color(N, -1);

    color[s] = init;

    queue<int> q;
    q.push(s);

    int ans = 0;
    vector<vpi> fake;
    bool bad = false;
    while(sz(q)) {
        auto &node = q.front();
        seen[node] = 1;
        q.pop();
    
        if (color[node] == VERT) swap(vert, hor);

        if (color[node] != start[node]) ans++;

        if (sz(hor[node]) != 2) bad = true;

        for (auto &[nxt, weight]: hor[node]) {
            if (nxt == BACK) continue;

            int targ = color[node];
            if (weight % 2 == 1) targ = (targ + 1) % 2;

            if (color[nxt] != -1 && color[nxt] != targ) {
                bad = true;
                break;
            }
            if (color[nxt] != -1) continue;
            color[nxt] = targ;
            q.push(nxt);
        }

        for (auto &[nxt, weight]: vert[node]) {
            if (nxt == BACK) continue;

            // say that others should not point to us
            int targ = (color[node] + 1) % 2;
            if (weight % 2 == 1) targ = (targ + 1) % 2;
            targ = (targ + 1) % 2;

            if (color[nxt] != -1 && color[nxt] != targ) {
                bad = true;
                break;
            }
            if (color[nxt] != -1) continue;
            color[nxt] = targ;
            q.push(nxt); 
        }

        if (color[node] == VERT) swap(vert, hor);

        if (bad) return -1;
    }

    return ans;
}


int solve(int tt) {
    memset(id, -1, sizeof(id));
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;

    rep(i, 0, n) cin >> grid[i];

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] == 'V') {
                start[N] = VERT;
                id[i][j] = N++;
            }
            if (grid[i][j] == 'H') {
                start[N] = HOR;
                id[i][j] = N++;
            }
        }
    }

    vector<vpi> hor(N), vert(N);

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (id[i][j] == -1) continue;

            pair<pi, pi> V = config(UP, DOWN, i, j);
            pair<pi, pi> H = config(LEFT, RIGHT, i, j);

            auto &[a, ha] = V.first;
            auto &[b, hb] = V.second;

            if (a != OBS) {
                vert[id[i][j]].pb({a, ha});
            }
            if (b != OBS) {
                vert[id[i][j]].pb({b, hb});
            }

        
            auto &[aa, haa] = H.first;
            auto &[bb, hbb] = H.second;
            if (aa != OBS) {
                hor[id[i][j]].pb({aa, haa});
            }
            if (bb != OBS) {
                hor[id[i][j]].pb({bb, hbb});
            }
        }
    }

    rep(i, 0, N) {
        if (sz(hor[i]) != 2 && sz(vert[i]) != 2) {
            cout << -1 << endl;
            return 0;
        } 
    }


    int ans = 0;


    // rep(i, 0, N) {
    //     cout << "VERT " << i << endl;
    //     for (auto &[x, weight]: vert[i]) {
    //         cout << x << " " << weight << " | ";
    //     }
    //     cout << endl;

    //     cout << "HOR " << i << endl;
    //     for (auto &[x, weight]: hor[i]) {
    //         cout << x << " " << weight << " | ";
    //     }
    //     cout << endl;
    // }


    // cout << hit[1][2][LEFT] << endl;



    rep(i, 0, N) {
        if (seen[i]) continue;
        int a = bfs(hor, vert, i, HOR);
        int b = bfs(hor, vert, i, VERT);

        if (a == -1 && b == -1) {
            cout << -1 << endl;
            return 0;
        }
        // cout << a << " " << b << endl;
        if (a == -1) ans += b;
        else if(b == -1) ans += a;
        else ans += min(a, b);
    }

    cout << ans << nl;

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