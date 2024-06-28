#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int grid[MAXN][MAXN];


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<double> vd;
const double eps = 1e-12;
int p;
int inv[100];

int solveLinear(vector<vi>& A, vi& b, vi& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		int v, bv = 0;
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

int power(int a, int b) {
    int res = 1;
    while(b) {
        if (b & 1) res *= a;
        a *= a;
        a %= p;
        res %= p;

        b >>= 1;
    }
    return res;
}


int main() {
    int n, m; cin >> n >> m >> p;

    for (int i = 1; i <= p; i++) {
        inv[i] = power(i, p - 2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            grid[i][j]--;
        }
    }


    // A * x = b

    vector<vi> A(n * m, vi(n * m));
    vi B(n * m);


    auto id = [&] (int i, int j) {
        return i * m + j;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int need = (p - 1) - grid[i][j];
            int a = id(i, j);
            B[a] = need;
            
            for (int ii = 0; ii < n; ii++) {
                A[a][id(ii, j)] = 1;
            }

            for (int jj = 0; jj < m; jj++) {
                A[a][id(i, jj)] = 1;
            }
        }
    }

    vector<int> ans(n * m);
    int res = solveLinear(A, B, ans);

    if (res == -1) {
        cout << -1 << endl;
        return 0;
    }

    int tot = 0;
    for (int i = 0; i < sz(ans); i++) {
        ans[i] = ((ans[i] % p) + p) % p;
        tot += ans[i];
    }

    cout << tot << endl;
    for (int i = 0; i < sz(ans); i++) {
        while(ans[i]--) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;


}