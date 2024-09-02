#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<double> P;
double ccRadius(const P& A, const P& B, const P& C) {
    return (B-A).dist()*(C-B).dist()*(A-C).dist()/
            abs((B-A).cross(C-A))/2;
}
P ccCenter(const P& A, const P& B, const P& C) {
    P b = C-A, c = B-A;
    return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}


int solve() {
    int n; cin >> n;
    if (n == 0) return 0;

    vector<P> pts(3);
    for (auto &p: pts) {
        cin >> p.x >> p.y;
    }

    double r = ccRadius(pts[0], pts[1], pts[2]);
    P c = ccCenter(pts[0], pts[1], pts[2]);

    double mnx = 1e9, mny = 1e9;
    double mxx = 0, mxy = 0;

    P cur = pts[0] - c;

    double angle = 2 * M_PI/n;
    while(n--) {
        mnx = min(cur.x, mnx);
        mny = min(cur.y, mny);

        mxx = max(cur.x, mxx);
        mxy = max(cur.y, mxy);
        cur = cur.rotate(angle);
    }

    double dx = mxx - mnx;
    double dy = mxy - mny;

    cout << setprecision(15) << fixed << dx * dy << endl;


    return 1;
}


int main() {
    while(solve());
}