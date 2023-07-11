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

struct Point {
    ll x, y;
    Point() {
        x = y = 0;
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    Point operator-(Point &rhs) {
        return Point(x - rhs.x, y - rhs.y);
    }
    bool operator>(Point &rhs) {
        if (x == rhs.x) return y > rhs.y;
        return x > rhs.x;
    }
};

ll cross (Point A, Point B) {
    return A.x * B.y - A.y * B.x;
}

int ccw(Point &A, Point &B, Point &C) {
    ll a = cross(B-A, C-B);
    if (a > 0) return 1;
    if (a == 0) return 0;
    return -1;
}

vector<int> CH(vector<Point> &P, vi &colin, int bad = -1) {
    vector<int> hull(sz(P) + 1);
    colin.assign(sz(P), 0);
    sort(all(P), [] (auto &a, auto &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
    int n = 0;
    vb inc(sz(P));
    rep(i, 0, sz(P)) {
        if (i == bad) continue;
        while (n >= 2) {
            int orientation = ccw(P[hull[n - 2]], P[hull[n - 1]], P[i]);
            if (orientation == 1) break;
            int prev = hull[n - 1];
            if (orientation == 0) {
                colin[i] += colin[prev] + 1;
            }
            colin[prev] = 0;
            n--;
        }
        hull[n++] = i;
    }
    int TH = n + 1;
    vi ccolin(sz(P));
    FORd(i, 0, sz(P) - 1) {
        if (i == bad || inc[i]) continue;
        while (n >= TH) {
            int orientation = ccw(P[hull[n - 2]], P[hull[n - 1]], P[i]);
            if (orientation == 1) break;
            int prev = hull[n - 1];
            if (orientation == 0) {
                ccolin[i] += ccolin[prev] + 1;
            }
            ccolin[prev] = 0;
            n--;
        }
        hull[n++] = i;
    }
    rep(i, 0, sz(P)) {
        colin[i] += ccolin[i];
    }
    while(sz(hull) >= n) hull.pop_back(); 
    return hull;
}

int solve(int tt) {
    int n;
    cin >> n;
    vector<Point> points(n);
    trav(p, points) cin >> p.x >> p.y;
    vi collinear;
    vector<int> hull = CH(points, collinear);
    if (sz(hull) < 3) {
        cout << 0 << nl;
        return 0;
    }
    int bad = -1;
    if (sz(hull) == 3) {
        // special case
        // is there a non collinear point in the entire set?
        int sm = 0;
        int cnt = 0;
        trav(i, hull) {
            sm += collinear[i];
            cnt += collinear[i] > 0;
        }

        // all points are either on the hull or collinear
        if (sm + sz(hull) == n) {
            if (cnt == 1) {
                cout << 0 << nl;
                return 0;
            }
            if (cnt == 2) {
                rep(i, 0, 3) {
                    int nxt = (i + 1) % 3; 
                    if (collinear[hull[i]] > 0 && collinear[hull[nxt]] > 0) {
                        assert(bad == -1);
                        bad = hull[i];
                    }
                }
                hull = CH(points, collinear, bad);
            }
        }
    }
    // should be a valid hull

    vector<Point> botHull, topHull;
    int mx = hull[0];
    rep(i, 0, sz(hull)) {
        if (points[hull[i]] > points[mx]) mx = hull[i];
    }
    rep(i, 0, sz(hull)) {
        botHull.pb(points[hull[i]]);
        if (hull[i] == mx) break;
    }
    topHull.pb(points[hull[0]]);
    FORd(i, 0, sz(hull)) {
        topHull.pb(points[hull[i]]);
        if (hull[i] == mx) break;
    }

    int left = topHull[0].x;
    int right = topHull.back().x;
    int S; cin >> S;
    vector<Point> castles(S);
    trav(c, castles) cin >> c.x >> c.y;

    int ans = 0;
    trav(c, castles) {
        if (c.x < left || c.x > right) continue;
        // is it bounded from above?
        int low = 0;
        int high = sz(topHull) - 2;
        if (topHull[0].x == topHull[1].x) low = 1;
        bool bounded_below = false;
        bool bounded_above = false;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (c.x < topHull[mid].x) {
                high = mid - 1;
                continue;
            } else if (c.x > topHull[mid + 1].x) {
                low = mid + 1;
                continue;
            }

            // this is correct line segment
            if (ccw(topHull[mid], c, topHull[mid + 1]) >= 0) bounded_above = true;
            break;
        }
        low = 0;
        high = sz(botHull) - 2;
        if (botHull[high].x == botHull[high + 1].x) high--;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (c.x < botHull[mid].x) {
                high = mid - 1;
                continue;
            } else if (c.x > botHull[mid + 1].x) {
                low = mid + 1;
                continue;
            }

            // this is correct line segment
            if (ccw(botHull[mid], c, botHull[mid + 1]) <= 0) bounded_below = true;
            break;
        }
        if (bounded_above && bounded_below) ans++;
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