#include <bits/stdc++.h>
using namespace std;

// #define double long double

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef __float128 ff;
const double EPS = 1e-8;

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


template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}

int main() {
    int n; cin >> n;
    
    typedef Point<ff> P;

    vector<P> pts(n);
    for (auto &p: pts) {
        int x, y;
        cin >> x >> y;
        p.x = x;
        p.y = y;
    }

    ff tot_area = polygonArea2(pts);
    ff sm = 0;
    P ans;
    for (int i = 2; i < n; i++) {
        sm += pts[i - 2].cross(pts[i - 1]);

        ff right = sm + pts[i - 1].cross(pts[i]) + pts[i].cross(pts[0]);

        if (right * 2.0 >= tot_area) {
            P low = pts[i - 1];
            P high = pts[i];

            int k = 1000000;
            while(k--) {
                P p = (low + high)/2;                
                ff area = sm + pts[i - 1].cross(p) + p.cross(pts[0]);
                if (area *2 <= tot_area) {
                    ans = p;
                    low = p;
                } else {
                    high = p;
                }
            }

            cout << setprecision(25) << fixed << (long double)ans.x << " " << (long double)ans.y << endl;
            return 0;
        }
    }


}