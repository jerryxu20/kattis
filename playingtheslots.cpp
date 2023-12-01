#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T> 
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0): x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) ==tie(p.x, p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y);}
    P operator-(P p) const {return P(x-p.x, y-p.y); }
    P operator* (T d) const {return P(x*d, y*d); }
    P operator/ (T d) const {return P(x/d, y/d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const {return x*x + y*y; }
    double dist() const {return sqrt((double)dist2()); }
    double angle() const {return atan2(y, x);}
    P unit() const {return *this/dist(); }
    P perp() const {return P(-y, x); }
    P normal() const {return perp().unit(); }
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a), x*sin(a) + y*cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

int main() {
    int n; cin >> n;
    vector<Point<double>> pts;
    rep(_, 0, n) {
        Point<double>p;
        cin >> p.x >> p.y;
        pts.pb(p);
    }
    double ans = 1e9;
    for (int i = 0; i < n; i++) {
        Point<double> a = pts[i];
        Point<double> b = pts[(i + 1) % n];
        double t = M_PI - (b - a).angle();

        double mx = 0;
        double mn = 0;
        for (int j = 0; j < n; j++) {
            pts[j] = (pts[j] - a).rotate(t);
            mx = max(pts[j].y, mx);
            mn = min(pts[j].y, mn);
        }        
        ans = min(ans, mx - mn);
    }
    cout << setprecision(20) << ans << endl;

}