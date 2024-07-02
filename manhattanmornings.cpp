#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

pi shift(const pi &pt, const pi &delta) {
    return {pt.first + delta.first, pt.second + delta.second};
}

pi scale(const pi &pt, const pi &delta) {
    return {pt.first * delta.first, pt.second * delta.second};
}

int main() {
    int n; cin >> n;

    pi s, t;
    cin >> s.first >> s.second;
    cin >> t.first >> t.second;


    pi delta = {-s.first, -s.second};
    s = shift(s, delta);
    t = shift(t, delta);

    pi c = {1, 1};
    if (t.first < 0) c.first = -1;
    if (t.second < 0) c.second = -1;
    t = scale(t, c);

    vector<pi> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
        pts[i] = scale(shift(pts[i], delta), c);
    }
    pts.push_back(t);

    sort(pts.begin(), pts.end(), [&] (auto &a, auto &b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });


    vector<int> X;
    X.push_back(0);


    for (auto &[x, _]: pts) {
        X.push_back(x);
    }
    sort(X.begin(), X.end());

    t.first = lower_bound(all(X), t.first) - X.begin();
    s.first = lower_bound(all(X), s.first) - X.begin();
    for (auto &[x, _]: pts) {
        x = lower_bound(all(X), x) - X.begin();
    }


    Tree seg(sz(X));
    for (auto &[x, y]: pts) {
        if (x < s.first || y < s.second || x > t.first || y > t.second) continue;
        int cand = seg.query(0, x + 1) + 1;
        seg.update(x, cand);
    } 
    cout << seg.query(t.first, t.first + 1) - 1 << endl;
}
