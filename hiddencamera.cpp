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
const double EPS = 1e-9;

struct Point {
    double x, y;
    Point() {
        x = y = 0;        
    }
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }

    Point operator/(int a) {
        return Point(x/a, y/a);
    }
    Point operator+(Point &rhs) {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator-(Point &rhs) {
        return Point(x - rhs.x, y - rhs.y);
    }
    
};

Point rotate(Point &A, int deg) {
    double rad = deg * M_PI / 180.0;
    return Point(A.x * cos(rad) - A.y * sin(rad),
                 A.x * sin(rad) + A.y * cos(rad));
}

struct Line {
    double m, b, mn, mx;
    Line(Point A, Point B) {
        Point C = B - A;
        if (abs(C.x) < EPS) C.x = EPS;
        m = C.y / C.x;
        b = A.y - m * A.x;
        mn = min(A.x, B.x);
        mx = max(A.x, B.x);
    }
    Line(double slope, Point A) {
        m = slope;
        b = A.y - m * A.x;
        mx = 20000;
        mn = -20000;
    }
    bool disjoint(double x) {
        return (mn - x) > EPS || (x - mx) > EPS;
    }
    
    double f(double x) {
        return m * x + b;
    }
};

bool intersects(Line &A, Line &B, Point &P) {
    // domains are disjoint
    if ((A.mn - B.mx) > EPS || (B.mn - A.mx) > EPS) return false;    
    
    double dm = A.m - B.m;
    double db = B.b - A.b;

    // same slope
    if (abs(dm) < EPS) return false;

    double x = db/dm;

    if (A.disjoint(x) || B.disjoint(x)) return false;
    double y = A.f(x);
    if (A.m > 1e9) {
        y = B.f(x);
    }
    P = Point(x, y);    
    return true;
}

double cross(Point &A, Point &B) {
    return A.x * B.y - A.y * B.x;
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
    int n;
    cin >> n;
    vector<Point> hull(n);
    trav(p, hull) {
        cin >> p.x >> p.y;
        p = rotate(p, 1);
    }
    Point mid = (hull[0] + hull[1])/2;
    // cout << mid.x << " " << mid.y << endl;
    // if (tt <= 16) return 0;
    Point delta = hull[1] - hull[0];
    Point slope1 = rotate(delta, 45);
    Point slope2 = rotate(delta, 90 + 45);
    // cout << slope1.x << " " << slope1.y << endl;
    // cout << slope2.x << " " << slope2.y << endl;
    if (abs(slope1.x) < EPS) slope1.x = EPS;
    if (abs(slope2.x) < EPS) slope2.x = EPS;

    Line W1 = Line(slope1.y/slope1.x, mid);
    Line W2 = Line(slope2.y/slope2.x, mid);
 
    vector<Point> pts = {mid};
    bool first_touch = false;
    bool second_touch = false;
    rep(i, 1, n) {
        Point A = hull[i];
        Point B = hull[(i + 1) % n];
        Point C;
        Line edge = Line(A, B);
        if (first_touch && !second_touch) {
            pts.pb(hull[i]);
        }
        if (intersects(W1, edge, C)) {
            // assert(first_touch == false && second_touch == false);
            first_touch = true;
            pts.pb(C);
        }

        if (intersects(W2, edge, C)) {
            // assert(first_touch == true && second_touch == false);
            second_touch = true;
            pts.pb(C);
        }
    }
    // trav(p, hull) {
    //     cout << p.x << " " << p.y << endl;
    // }
    // cout << "new hull\n";
    // trav(p, pts) {
    //     cout << p.x << " " << p.y << endl;
    // }

    // vector<Point> camHull = CH(pts);
    // cout << shoelace(pts) << endl;
    // cout << shoelace(hull) << endl;
    if (shoelace(hull) < EPS) {
        cout << 100 << endl;
        return 1;
    }
    cout << setprecision(15) << fixed << shoelace(pts) / shoelace(hull) << endl;

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