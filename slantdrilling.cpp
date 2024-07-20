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

typedef Point<double> Pt;
double segDist(const Pt& s, const Pt& e, const Pt& p) {
	if (s==e) return (p-s).dist();
	double d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}


template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
	int cnt = 0, n = sz(p);
	rep(i,0,n) {
		P q = p[(i + 1) % n];
		if (onSegment(p[i], q, a)) return !strict;
		//or: if (segDist(p[i], q, a) <= eps) return !strict;
		cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
	}
	return cnt;
}

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}

typedef Point<ll> P;
const int MAXN = 1e6;
int inside[MAXN], outside[MAXN];
vector<P> poly[MAXN]; 
ll area[MAXN];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> outside[i] >> inside[i];

        int m; cin >> m;
        while(m--) {
            int x, y; cin >> x >> y;
            poly[i].push_back(P(x, y));
        }

        area[i] = polygonArea2(poly[i]);   
    }

    vector<int> idx(n);
    iota(all(idx), 0);

    sort(all(idx), [&] (auto &a, auto &b) {
        return area[a] < area[b]; 
    });

    int found = 0;

    double ans = 1e9;
    for (int i: idx) {
        bool in = inPolygon(poly[i], P(0, 0), 1);
        
        if (!found && in) {
            found++;
            ans = min(ans, (double)inside[i]);
        }

        // check along edges
        for (int j = 0; j < sz(poly[i]); j++) {
            int k = (j + 1) % sz(poly[i]);

            double xy = segDist(Pt(poly[i][j].x, poly[i][j].y), Pt(poly[i][k].x, poly[i][k].y), Pt(0, 0));
            ll h = min(inside[i], outside[i]);
            ans = min(ans, sqrt(xy * xy + h * h));
        }
    }

    if (found == 0) {
        ans = min(ans, (double)outside[idx.back()]);
    }

    cout << fixed << setprecision(20) << ans << endl;
}