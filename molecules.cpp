#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<double> vd;
const double eps = 1e-12;

int solveLinear(vector<vd>& A, vd& b, vd& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		double v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = fabs(A[r][c])) > bv)
				br = r, bc = c, bv = v;
		if (bv <= eps) {
			rep(j,i,n) if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = 1/A[i][i];
		rep(j,i+1,n) {
			double fac = A[j][i] * bv;
			b[j] -= fac * b[i];
			rep(k,i+1,m) A[j][k] -= fac*A[i][k];
		}
		rank++;
	}

	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] /= A[i][i];
		x[col[i]] = b[i];
		rep(j,0,i) b[j] -= A[j][i] * b[i];
	}
	return rank; // (multiple solutions if rank < m)
}

const int MAXN = 100;
int X[MAXN], Y[MAXN];

int main() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n);

    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }

    while(m--) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vd> A(n, vd(n));
    vd B(n);

    for (int i = 0; i < n; i++) {
        if (X[i] != -1) {
            A[i][i] = 1;
            B[i] = X[i];
            continue;
        }

        A[i][i] = sz(adj[i]);
        for (int &j: adj[i]) {
            A[i][j] = -1;
        }
    }

    vd xans(n);
    solveLinear(A, B, xans);

    A.assign(n, vd(n));
    B.assign(n, 0);
    
    for (int i = 0; i < n; i++) {
        if (Y[i] != -1) {
            A[i][i] = 1;
            B[i] = Y[i];
            continue;
        }

        A[i][i] = sz(adj[i]);
        for (int &j: adj[i]) {
            A[i][j] = -1;
        }
    }
    
    vd yans(n);
    solveLinear(A, B, yans);

    cout << setprecision(10) << fixed;
    for (int i = 0; i < n; i++) {
        cout << xans[i] << " " << yans[i] << endl;
    }
    
}