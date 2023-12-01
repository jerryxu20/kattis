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
    ll x, y;
    Point(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }

    Point operator-(Point rhs) {
        return Point(x - rhs.x, y - rhs.y);
    }

    ll d2() {
        return x * x + y * y;
    }
};

ll tri(Point a, Point b, Point c) {
    return abs((b - a).x * (c - a).y - (c - a).x * (b - a).y);
}


int solve(int tt) {
    int n, m; cin >> n >> m;

    n++;
    vector<Point> pts(n);
    for (auto &p: pts) cin >> p.x >> p.y;

    vector<int> time(n);
    PQG<tuple<ll, double, double>> pq;

    vi to_left(n), to_right(n);
    iota(all(to_left), -1);
    iota(all(to_right), 1);
    // area, index, time
    for (int i = 1; i + 1 < n; i++) {
        double area = tri(pts[i - 1], pts[i], pts[i + 1]);
        pq.push({area, i, 0});
    }

    int t = 1;
    int segments = n - 1;
    while(segments != m) {
        while(sz(pq)) {
            auto [area, idx, updated] = pq.top();
            if (time[idx] == -1 || updated != time[idx]) {
                pq.pop();
                continue;
            }
            break;
        }
        // if (sz(pq) == 0) break;
        auto [area, idx, updated] = pq.top();
        assert(time[idx] == updated);
        pq.pop();
        time[idx] = -1;
        cout << idx << nl;
        
        // when idx - 1 queries right, it should be my right
        int l = to_left[idx];
        int r = to_right[idx];
    
        if (l >= 0 && l < n) {
            time[l] = t;
            to_right[l] = r;
        }
        if (r >= 0 && r < n) {
            time[r] = t;
            to_left[r] = l;
        }
        if (l >= 0 && l < n && to_left[l] >= 0 && to_right[l] < n) {
            double new_area = tri(pts[to_left[l]], pts[l], pts[to_right[l]]);
            pq.push({new_area, l, t});
        }
        if (r >= 0 && r < n && to_left[r] >= 0 && to_right[r] < n) {
            double new_area = tri(pts[to_left[r]], pts[r], pts[to_right[r]]);
            pq.push({new_area, r, t});
        }
        t++;
        segments--;
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