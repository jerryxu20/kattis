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

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
    int idx;
	explicit Point(T x=0, T y=0, int idx = -1) : x(x), y(y), idx(idx) {}
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

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

const double eps = 1e-9;
template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
	int cnt = 0, n = sz(p);
	rep(i,0,n) {
		P q = p[(i + 1) % n];
		if (onSegment(p[i], q, a)) return !strict;
		// if (segDist(p[i], q, a) <= eps) return !strict;
		cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
	}
	return cnt;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

int solve(int tt) {
    int n; cin >> n;
    vi X(n), Y(n);
    trav(a, X) cin >> a;
    trav(a, Y) cin >> a;
    bool found = false;
    vector<double> ans(n);
    int xx, yy;
    cin >> xx >> yy;
    vector<Point<ll>> pts;
    rep(i, 0, n) {
        if (xx == X[i] && yy == Y[i]) {
            ans[i] = 1;
            found = true;
            break;
        }
        pts.pb(Point<ll>(X[i], Y[i], i));
    }
    auto hull = convexHull(pts);
    if (!found && !inPolygon(hull, Point<ll>(xx, yy), false)) {
        cout << "No\n";
        return 0;
    }

    vector<Point<double>> dhull;
    trav(p, hull) {
        dhull.pb(Point<double>(p.x, p.y, p.idx));
    }

    int s = sz(dhull);
    Point<double> P(xx, yy);
    rep(i, 0, s) {
        if (found) break;
        rep(j, 0, s) {
            if (found) break;
            if (j == i || (j + 1) % s == i) continue; 
            Point<double> delta = P - dhull[i];
            Point<double> far = P + delta * 1e4;

            auto inter = segInter(P, far, dhull[j], dhull[(j + 1) % s]);
            if (sz(inter) == 0) continue;
            assert(sz(inter) == 1);
            auto k = inter[0];
            auto x = dhull[i];
            auto y = dhull[j];
            auto z = dhull[(j + 1) % sz(hull)];

            double a = (P - k).dist() / (x - k).dist();
            double b = (z - k).dist() / (y - z).dist() * (1 - a);
            double c = (y - k).dist() / (y - z).dist() * (1 - a);

            assert(abs(a + b + c - 1) < eps);
            ans[x.idx] = a;
            ans[y.idx] = b;
            ans[z.idx] = c;
            found = true;
            break;

        } 
    }

    rep(i, 0, n) {
        if (found) break;
        auto a = dhull[i];
        auto b = dhull[(i + 1) % s];
        if (onSegment(a, b, P));

        double A = (b - P).dist() / (a - b).dist();
        double B = (a - P).dist() / (a - b).dist();

        ans[a.idx] = A;
        ans[b.idx] = B;
        found = true;
    }

    assert(found);
    cout << "Yes\n";
    cout << setprecision(20);
    trav(mix,ans) {
        cout << mix << " ";
    }
    cout << nl;
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