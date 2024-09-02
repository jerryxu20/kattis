#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const double EPS = 1e-9;

// 12:20

template <class T> int sgn(T x) {return (x > 0) - (x < 0); }
template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const {return (a-*this).cross(b-*this); }
    T dist2() const { return x * x + y * y; }

    double dist() const {return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const {return *this/dist(); }
    P perp() const {return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};



template<class P>
int sideOf(const P&s, const P&e, const P&p, double eps) {
    auto a = (e - s).cross(p - s);
    double l = (e - s).dist() * eps;
    return (a > l) - (a < -l);
}

typedef Point<double> P;
double segDist(P &s, P&e, P& p) {
    if (s == e) return (p - s).dist();
    auto d = (e - s).dist2(), t = min(d, max(.0, (p - s).dot(e - s)));
    return ((p-s) * d - (e-s)*t).dist()/d;
}

template<class P> bool onSegment(P s, P e, P p) {
    return segDist(s, e, p) <= EPS;
}


typedef Point<double> P;
bool inHull(const vector<P>&l, P p, bool strict = true) {
    int a = 1, b = sz(l) - 1, r = !strict;
    if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);
    if (sideOf(l[0], l[a], l[b], EPS) > 0) swap(a, b);
    if (sideOf(l[0], l[a], p, EPS) >= r || sideOf(l[0], l[b], p, EPS) <= -r) return false;
    while(abs(a - b) > 1) {
        int c = (a + b)/2;
        (sideOf(l[0], l[c], p, EPS) > 0 ? b : a) = c;
    } 

    return sgn(l[a].cross(l[b], p)) < r;
}



int n;
const int MAXN = 1000;
Point<double> pts[MAXN];

int inside(vector<Point<double>> &poly) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (inHull(poly, pts[i], false)) ans++;
    }
    return ans;
}

double inner(vector<Point<double>> &poly) {
    double low = 1;
    double high = 1e9;

    double ans = 1;
    int k = 500;
    while(k--) {
        double mid = (low + high)/2;

        vector<Point<double>> arr = poly;
        for (auto &p: arr) {
            p = p * mid;
        }
        int x = inside(arr);
        if (x == 0) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }

    return ans;
}

double outer(vector<Point<double>> &poly) {
    double low = 1;
    double high = 1e9;

    double ans = 1e9;
    int k = 500;
    while(k--) {
        double mid = (low + high)/2;

        vector<Point<double>> arr = poly;
        for (auto &p: arr) {
            p = p * mid;
        }
        int x = inside(arr);
        if (x == n) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    return ans;
}

template<class T>
T polygonArea2(vector<Point<T>> &v) {
    T a = v.back().cross(v[0]);
    rep(i, 0, sz(v) - 1) a += v[i].cross(v[i + 1]);
    return a;
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    int ans = -1;
    double best = -1;
    for (int k = 3; k <= 8; k++) {
        Point<double> cur(1, 0);

        double delta = 2.0 * M_PI / k;
        vector<Point<double>> poly;
        for (int i = 0; i < k; i++) {
            poly.push_back(cur);
            cur = cur.rotate(delta);
        }


        double rin = inner(poly);
        double rout = outer(poly);

        for (auto &p: poly) {
            p = p.unit() * rin;
        }

        double ain = polygonArea2(poly);

        for (auto &p: poly) {
            p = p.unit() * rout;
        } 
        double aout = polygonArea2(poly);

        double cand = (rin * rin)/ (rout * rout);
        if (cand > best) {
            best = cand;
            ans = k;
        }
    }
    assert(ans != -1);

    cout << fixed << setprecision(15) << ans << " " << best << endl;
}