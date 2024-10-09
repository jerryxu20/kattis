#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
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

const int MAXN = 1e6 + 2;
int arr[MAXN];
int main() {	
	int n; cin >> n;
	rep(i, 0, n) cin >> arr[i];

	Tree a(MAXN, 0), b(MAXN, 0);

	rep(i, 0, n) {
		a.update(arr[i], b.query(0, arr[i]) + 1);
		b.update(arr[i], a.query(arr[i] + 1, MAXN) + 1);
	}

	cout << max(a.query(0, MAXN), b.query(0, MAXN)) << endl;
	return 0;	
}