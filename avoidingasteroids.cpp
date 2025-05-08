#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class P>
double lineDist(const P& a, const P& b, const P& p) {
	return (double)(b-a).cross(p-a).dist()/(b-a).dist();
}

template<class T> struct Point3D {
	typedef Point3D P;
	typedef const P& R;
	T x, y, z;
	explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
	bool operator<(R p) const {
		return tie(x, y, z) < tie(p.x, p.y, p.z); }
	bool operator==(R p) const {
		return tie(x, y, z) == tie(p.x, p.y, p.z); }
	P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
	P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
	P operator*(T d) const { return P(x*d, y*d, z*d); }
	P operator/(T d) const { return P(x/d, y/d, z/d); }
	T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
	P cross(R p) const {
		return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	T dist2() const { return x*x + y*y + z*z; }
	double dist() const { return sqrt((double)dist2()); }
	//Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
	double phi() const { return atan2(y, x); } 
	//Zenith angle (latitude) to the z-axis in interval [0, pi]
	double theta() const { return atan2(sqrt(x*x+y*y),z); }
	P unit() const { return *this/(T)dist(); } //makes dist()=1
	//returns unit vector normal to *this and p
	P normal(P p) const { return cross(p).unit(); }
	//returns point rotated 'angle' radians ccw around axis
	P rotate(double angle, P axis) const {
		double s = sin(angle), c = cos(angle); P u = axis.unit();
		return u*dot(u)*(1-c) + (*this)*c - cross(u)*s;
	}
};
typedef Point3D<double> P;

// typedef Point<double> P;
double segDist(const P& s, const P& e, const P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

int main() {

    P s, t;
    cin >> s.x >> s.y >> s.z;
    cin >> t.x >> t.y >> t.z;
    int n; cin >> n;
    vector<P> center(n), dir(n);
    vector<vector<P>> hull(n);
    rep(i, 0, n) {
        cin >> center[i].x >> center[i].y >> center[i].z;
        cin >> dir[i].x >> dir[i].y >> dir[i].z;

        int m; cin >> m;
        hull[i].resize(m);
        for (auto &p: hull[i]) {
            cin >> p.x >> p.y >> p.z;
        }
    }

    rep(i, 0, n) {
        double dis = 0;
        for (auto &p: hull[i]) {
            dis = max(dis, (p - center[i]).dist());
        }

        P a = center[i];
        P b = center[i] + dir[i].unit() * 5e18;

        P delta = t - s;
        double low = 0;
        double high = 1;
        int k = 100;
        double mn = 1e18;
        while(k--) {
            double l = (high - low)/3 + low;
            double r = high - (high - low)/3;

            double L = segDist(a, b, s + delta * l); 
            double R = segDist(a, b, s + delta * r);
            mn = min({mn, L, R});
            if (L < R) {
                high = r;
            } else {
                low = l;
            }
        }
        if (mn < dis) {
            cout << "Surrender\n";
            return 0;
        }
    }

    cout << "Go\n";
}