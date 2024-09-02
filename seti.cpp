#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const int MAXN = 30005;
int inv[MAXN];
int MOD;

int solveLinear(vector<vi>& A, vi& b, vi& x) {
    ll p = MOD;
	ll n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		ll v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = abs(A[r][c])) > bv)
				br = r, bc = c, bv = v;

		if (bv == 0) {
			rep(j,i,n) if (abs(b[j]) > 0) return -1;
			break;
		}

		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = 1 * inv[A[i][i]];
		rep(j,i+1,n) {
			int fac = (A[j][i] * bv) % p;
			b[j] -= (fac * b[i]) % p;
            b[j] = ((b[j] % p) + p) % p;
			rep(k,i+1,m) {
                A[j][k] -= fac*A[i][k];
                A[j][k] = ((A[j][k] % p) + p) % p;
            }
		}
		rank++;
	}

	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] *= inv[A[i][i]];
        b[i] %= p;
		x[col[i]] = b[i];
		rep(j,0,i) {
            b[j] -= A[j][i] * b[i];
            b[j] = ((b[j] % p) + p) % p;
        }
	}
	return rank; // (multiple solutions if rank < m)
}

int power(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res *= a;
        a *= a;
        b/=2;

        res %= MOD;
        a %= MOD;
    }
    return res;
}

void solve() {
    cin >> MOD;

    for (int i = 1; i < MAXN; i++) {
        inv[i] = power(i, MOD - 2);
    }

    string s; cin >> s;
    vi vals;

    for (char &c: s) {
        if (c == '*') vals.push_back(0);
        else vals.push_back(c - 'a' + 1);
    }

    int n = vals.size();

    vector<vi> A(n, vi(n));
    vi ans(n);
    for (int k = 1; k <= n; k++) {
        int cur = 1;
        for (int j = 0; j < n; j++) {
            A[k - 1][j] = cur;
            cur *= k;
            cur %= MOD;
        }
    }

    assert(solveLinear(A, vals, ans) != -1);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}