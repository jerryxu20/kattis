#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int p = 13;
int inv[15];

int solveLinear(vector<vi>& A, vi& b, vi& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);



	rep(i,0,n) {
		int v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = abs(A[r][c])) > bv)
				br = r, bc = c, bv = v;

		if (bv <= 0) {
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

int power(int a, int b) {
    int res = 1;
    while(b) {
        if (b & 1) res *= a;
        a *= a;
        b /= 2;
        
        a %= p;
        res %= p;
    }
    return res;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    for (int i = 0; i < 15; i++) {
        inv[i] = power(i, p - 2);
    }
    
    int n, a, r, t; cin >> n >> a >> r >> t;
    int N = 0;
    vector<vector<int>> ID(n, vector<int>(n, -1));

    auto id = [&] (int i, int j) {
        if (i > j) swap(i, j);
        if (ID[i][j] == -1) ID[i][j] = N++;
        return ID[i][j];
    };
    
    vector<vi> A(t, vector<int>(200, 0));
    vector<int> vals;
    
    vector<vi> paths;
    for (int i = 0; i < t; i++) {
        int d, l; cin >> d >> l;
        vals.push_back(d);


        vector<int> path;
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            x--; path.push_back(x);
        }

        for (int j = 1; j < l; j++) {
            int a = id(path[j - 1], path[j]);
            A[i][a]++;
            A[i][a] %= p;
        }

        paths.push_back(path);
    }

    vector<int> ans(200);
    solveLinear(A, vals, ans);

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) dp[i][i] = 0;

    for (auto &path: paths) {
        for (int i = 1; i < sz(path); i++) {
            int x = id(path[i - 1], path[i]);
            dp[path[i - 1]][path[i]] = ans[x];
            dp[path[i]][path[i - 1]] = ans[x];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][k] == INT_MAX || dp[k][j] == INT_MAX) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    cout << dp[a - 1][r - 1] << endl;
}