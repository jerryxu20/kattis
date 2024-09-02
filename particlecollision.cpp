#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
int r;

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

double lineDist(const P& a, const P& b, const P& p) {
	return (double)(b-a).cross(p-a)/(b-a).dist();
}

bool hit(P s, P delta, P p) {
    P e = s + delta.unit() * 2000;
    return segDist(s, e, p) <= 2 * r;
}

P lineProj(P a, P b, P p, bool refl=false) {
	P v = b - a;
	return p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();
}

double hitdis(P a, P delta, P t) {

    if (!hit(a, delta, t)) return 1e9;

    P e = a + delta.unit() * 2000;
    P p = lineProj(a, e, t);

    double low = 0;
    double high = (p - a).dist();
    int k = 300;
    double ans = -1;
    bool hit = false;
    while(k--) {
        double mid = (low + high)/2;
        p = a + delta.unit() * mid;

        if ((t - p).dist() <= 2 * r) {
            ans = mid;
            high = mid;
            hit = true;
        } else {
            low = mid;
        }
    }
    return low;
}

P collide(P a, P delta, P t) {
    double d = hitdis(a, delta, t);
    P p = a + delta.unit() * d;
    return (t - p).unit();
}

int main() {
    P a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    cin >> r;
    if (!hit(a, d, b) && !hit(a, d, c)) {
        cout << 5 << endl;
        return 0;
    }

    if (!hit(a, d, c) || (hitdis(a, d, b) < hitdis(a, d, c))) {
        assert(hit(a, d, b));
        d = collide(a, d, b);
        if (!hit(b, d, c)) {
            cout << 3 << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        assert(hit(a, d, c));
        d = collide(a, d, c);
        if (!hit(c, d, b)) {
            cout << 4 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}