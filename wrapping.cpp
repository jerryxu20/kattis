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
    double x, y;
    Point() {
        x = y = 0;
    }
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    Point& operator+=(Point rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Point operator+(Point rhs) {
        return Point(x + rhs.x, y + rhs.y);
    }
    bool operator<(Point &rhs) {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
    Point operator-(Point &rhs) {
        return Point(x - rhs.x, y - rhs.y);
    }
};

// rotate p CW by d degrees
Point rotate(Point& p, double d) {
    double theta = 2 * M_PI - d * M_PI / 180.0;
    return Point(p.x * cos(theta) - p.y * sin(theta),
                 p.x * sin(theta) + p.y * cos(theta));
}

double cross(const Point &A, const Point &B) {
    return A.x * B.y - A.y * B.x;
}

bool ccw(Point &A, Point &B, Point &C) {
    return cross(B - A, C - B) > 0;
}

vector<Point> convexHull(vector<Point> &P) {
    vector<Point> top(sz(P)), bot(sz(P));
    sort(all(P));
    int n;
    rep(_, 0, 2) {
        n = 0;
        trav(p, P) {
	        // pop from stack 
            while (n >= 2 && !ccw(bot[n - 2], bot[n - 1], p)) n--;

			// push current point to stack
			bot[n++] = p;
        }
        reverse(all(P));
        bot.resize(n);
        swap(top, bot);
    }
    // top hull (right to left) + bot hull (left to right)
    rep(i, 1, n) {
        bot.pb(top[i]);
    }
    return bot;
}

double shoelace(vector<Point> &pts) {
    double ans = 0;
    int n = sz(pts);
    rep(i, 0, n) {
        ans += cross(pts[i], pts[(i + 1) % n]);
    }
    return abs(ans)/2.0;
}


int solve(int tt) {
    int n; cin >> n;
    double board_area = 0;

    double x, y, w, h, v;
    vector<Point> pts;
    while(n--) {
        cin >> x >> y >> w >> h >> v;
        vector<Point> corners = {Point(-w/2, -h/2), Point(-w/2, h/2), Point(w/2, h/2), Point(w/2, -h/2)};
        Point center(x, y);
        trav(p, corners) {
            pts.pb(rotate(p, v) + center);
        }
        board_area += w * h;
    }

    vector<Point> hull = convexHull(pts);
    double total_area = shoelace(hull);
    assert(total_area >= board_area);
    cout << setprecision(1) << fixed << board_area/total_area * 100 << " %\n";
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