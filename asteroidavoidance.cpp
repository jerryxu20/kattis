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

int w, h, n, m;
vector<ti> asteroid;

int min_dis(int x, int y, int xx, int yy) {
    vpi coords = {{x, y}, {x, y + h}, {x + w, y + h}, {x + w, y}};

    if (x <= xx && xx <= x + w && y <= yy && yy <= y + h) return 0; 

    int ans = INT_MAX;
    rep(i, 0, sz(coords)) {
        int j = (i + 1) % 4;
        // vertical line
        if (coords[i].first == coords[j].first) {
            int mn = min(coords[i].second, coords[j].second);
            int mx = max(coords[i].second, coords[j].second);
            if (mn <= yy && yy <= mx) {
                int d = xx - coords[i].first;
                ans = min(ans, d * d);
            }
        } else {
            int mn = min(coords[i].first, coords[j].first);
            int mx = max(coords[i].first, coords[j].first);
            if (mn <= xx && xx <= mx) {
                int d = yy - coords[i].second;
                ans = min(ans, d * d);
            }
        }
        int dx = xx - coords[i].first;
        int dy = yy - coords[i].second;
        ans = min(ans, dx * dx + dy * dy);
    }
    return ans;
}

bool valid(int x, int y) {

    for (auto &[xx, yy, r]: asteroid) {
        if (min_dis(x, y, xx, yy) <= r * r) return false;
    }
    return true;
}

int solve(int tt) {
    // a destination is safe iff no asteroid is touching our ship 
    cin >> w >> h >> n >> m;
    asteroid.resize(n);
    for (auto &[x, y, r]: asteroid) cin >> x >> y >> r;

    vector<pi> location(m);
    for (auto &[x, y]: location) cin >> x >> y;

    for (auto &[x, y]: location) {
        if (valid(x, y)) {
            cout << "DOOMSLUG GO!\n";
        } else {
            cout << "DOOMSLUG STOP!\n";
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