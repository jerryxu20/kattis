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

vii grid;
int n, m;
vii delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void bfs(vii &dis, queue<pi> &q) {

    PQG<ti> pq;
    while(sz(q)) {
        auto [i, j] = q.front();
        q.pop();
        pq.push({0, i, j});
        dis[i][j] = 0;
    }

    while(sz(pq)) {
        auto [d, i, j] = pq.top();
        pq.pop();
        if (d != dis[i][j]) continue;
        for (auto &dt: delta) {
            int ii = i + dt[0];
            int jj = j + dt[1];
            if (ii < 0 || jj < 0 || ii >= n || jj >= m || grid[ii][jj] == -1) continue;
            int cost = grid[i][j] + d;
            if (cost >= dis[ii][jj]) continue;
            dis[ii][jj] = cost;
            pq.push({cost, ii, jj});
        }
    }
    return;
}

int solve(int tt) {
    cin >> n >> m;
    vs jail(n);
    trav(row, jail) cin >> row;

    grid.assign(n, vi(m));
    vpi people;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (jail[i][j] == '*') grid[i][j] = -1;
            if (jail[i][j] == '#') grid[i][j] = 1;
            if (jail[i][j] == '$') people.pb(mp(i, j));
        }
    }
    
    queue<pi> outside, p1, p2;
    p1.push(people[0]);
    p2.push(people[1]);
    rep(i, 0, n) {
        if (grid[i][0] != -1) {
            outside.push(mp(i, 0));
        }
        if (grid[i][m - 1] != -1) {
            outside.push(mp(i, m - 1));
        }
    }

    rep(j, 1, m - 1) {
        if (grid[0][j] != -1) {
            outside.push(mp(0, j));
        }
        if (grid[n - 1][j] != -1) {
            outside.push(mp(n - 1, j));
        }
    }

    vii dis1(n, vi(m, INT_MAX)), dis2(n, vi(m, INT_MAX)), dis3(n, vi(m, INT_MAX));
    bfs(dis1, outside);
    bfs(dis2, p1);
    bfs(dis3, p2);

    int ans = INT_MAX;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] == -1) continue;
            if (max({dis1[i][j], dis2[i][j], dis3[i][j]}) == INT_MAX) continue;
            ans = min(ans, grid[i][j] + dis1[i][j] + dis2[i][j] + dis3[i][j]);
        }
    }
    cout << ans << nl;
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}