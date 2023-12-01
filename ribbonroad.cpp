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

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}


int solve(int tt) {
    int n; cin >> n;
    vector<Point<ll>> pts(n);
    trav(p, pts) {
        cin >> p.x >> p.y;
    }
    if (polygonArea2(pts) <= 0) reverse(all(pts));

    Point<ll> cur, ray;
    cin >> cur.x >> cur.y;
    cin >> ray.x >> ray.y;
    int vert = -1;
    string ans = "";
    rep(i, 0, n) {
        Point<ll> p = pts[i];
        Point<ll> q = pts[(i + 1) % n];
        if (p == cur) {
            vert = i;
            break;
        }
    }

    // its on an edge
    if (vert == -1) {
        rep(i, 0, n) {
            Point<ll> p = pts[i];
            Point<ll> q = pts[(i + 1) % n];
            if (!onSegment(p, q, cur)) continue;
            
            // I am on this edge
            ll res = (q - p).cross(ray - cur);
            if (res == 0) {
                cout << "?\n";
            } else if (res > 0) {
                cout << "inside\n";
            } else {
                cout << "outside\n";
            }
            return 0;
        }
        assert(false);
    }


    // it's on a vertex
    Point<ll> p = pts[vert];
    assert(p == cur);

    Point<ll> nxt = pts[(vert + 1) % n];
    Point<ll> prev = pts[(vert - 1 + n) % n];

    ll res1 = (nxt - p).cross(ray - p);
    ll res2 = (ray - p).cross(prev - p); 

    if (res1 == 0 || res2 == 0) {
        cout << "?\n";
        return 0;
    }

    if (res1 > 0 && res2 > 0) {
        cout << "inside\n";
        return 0;
    }

    if (res1 < 0 && res2 < 0) {
        cout << "outside\n";
        return 0;
    }
    cout << "?\n";


    tt++;
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