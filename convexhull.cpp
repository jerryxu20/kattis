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


struct Point {
    int x, y;
    Point() {
        x = y = 0;
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    Point operator-(Point &rhs) {
        return Point(x-rhs.x, y-rhs.y);
    }

    bool operator<(Point &rhs) {
        if (x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }

    bool operator==(Point &rhs) {
        return rhs.x == x && rhs.y == y;
    }
};
 
int cross(Point A, Point B) {
    return A.x * B.y - A.y * B.x;
}

bool ccw(Point &A, Point &B, Point &C) {
    // A -> B -> C
    return cross(B-A, C-B) > 0;
}

vector<Point> ConvexHull(vector<Point>& P) {
    sort(P.begin(), P.end());
    vector<Point> botHull(sz(P)), topHull(sz(P));

    int n = 0;
    for (auto &point: P) {
        while (n >= 2 && !ccw(botHull[n - 2], botHull[n - 1], point)) n--;
        if (n && botHull[n - 1] == point) continue;
        botHull[n++] = point;
    }
    while(sz(botHull) > n) botHull.pop_back();

    reverse(P.begin(), P.end());

    n = 0;
    for (auto &point: P) {
        while(n >= 2 && !ccw(topHull[n - 2], topHull[n - 1], point)) n--;
        if (n && topHull[n - 1] == point) continue;
        topHull[n++] = point;
    }
    for (int i = 1; i < n - 1; i++) {
        botHull.pb(topHull[i]);
    }
    return botHull;
}

int solve(int tt) {
    int n;
    cin >> n;
    if (n == 0) return 1;
    vector<Point> points(n);
    trav(p, points) {
        cin >> p.x >> p.y;
    }
    vector<Point> hull = ConvexHull(points);
    cout << sz(hull) << nl;
    trav(p, hull) {
        cout << p.x << " " << p.y << nl;
    }

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}