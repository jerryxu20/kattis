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
const double EPS = 1e-6;


struct Point {
    double x, y;

    Point(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
        return;
    }

    double size() {
        return sqrt(x * x + y * y);
    }

    Point operator-(Point rhs) {
        return Point(x - rhs.x, y - rhs.y);
    }
};

struct Line {
    bool vert = false;
    double slope, inter, x;

    Line(int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        // rise/run -> dy/dx
        if (dx == 0) {
            vert = true;
            x = x1;
            return;
        }

        slope = (double)dy/dx;
        inter = y1 - slope * x1;
    }

    double at(double _x) {
        assert(!vert);
        return slope * _x + inter;
    }
};

bool intersect(Line a, Line b, Point &p) {
    if (a.vert && b.vert) return false;
    if (b.vert) swap(a, b);

    double X, Y;
    if (a.vert) {
        X = a.x;
        Y = b.at(a.x);
        p.x = X;
        p.y = Y;
        return true;
    }

    if (abs(a.slope - b.slope) < EPS) return false;
    X = (b.inter - a.inter)/(a.slope - b.slope);
    Y = a.at(X);

    p.x = X;
    p.y = Y;
    return true;
}


int solve(int tt) {
    int n; cin >> n;
    int x1, x2, y1, y2;
    vector<Line> line;
    for(int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        line.pb(Line(x1, y1, x2, y2));
    }

    double ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                Line a = line[i];
                Line b = line[j];
                Line c = line[k];

                Point p1, p2, p3;
                if (!intersect(a, b, p1)) continue;
                if (!intersect(a, c, p2)) continue;
                if (!intersect(b, c, p3)) continue;

                double s1 = (p1 - p2).size();
                double s2 = (p1 - p3).size();
                double s3 = (p2 - p3).size();

                ans = max(ans, s1 + s2 + s3);
            }
        }
    }

    if (ans > EPS) {
        cout << setprecision(15) << ans << nl;
    } else {
        cout << "no triangle\n";
    }

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