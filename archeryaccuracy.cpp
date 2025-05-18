#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 17;
int n;

double hit[MAXN];
int threshold[MAXN + 1];
double dp[1 << MAXN];

pair<double, double> prob_dp[MAXN][MAXN + 1][2];
int valid_prob[MAXN][MAXN + 1][2];

typedef vector<double> vd;
const double eps = 1e-12;

int solveLinear(vector<vd> A, vd b, vd& x) {
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

pair<double, double> calc(int dude, int idx, int pos) {
    // [prob of pos targ, prob of neg targ] 
    if (valid_prob[dude][idx][pos]) return prob_dp[dude][idx][pos];

    int targ = threshold[idx];
    int prev = threshold[idx - 1];
    if (pos == 0) prev *= -1;

    double prob = hit[dude];

    int a = targ - prev;
    int b = prev - (-targ);
    vector<int> vars;
    int nxt = 0;
    for (int i = 0; i < b; i++) {
        vars.push_back(nxt++);
    }
    int x = nxt++;
    vars.push_back(nxt);

    for (int i = 0; i < a; i++) {
        vars.push_back(nxt++);
    }

    int n = vars.size();
    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);

    B[0] = 0;
    B.back() = 1;

    for (int i = 1; i + 1 < n; i++) {
        // i = prob * (i + 1) + (1 - prob) * (i - 1)
        A[i][i] = -1;
        A[i][i - 1] = (1 - prob);
        A[i][i + 1] = prob;
    }
    A[0][0] = 1;
    A[n - 1][n - 1] = 1;

    vector<double> X(n);
    int r = solveLinear(A, B, X);
    assert(r == n);
    double p = X[x];

    prob_dp[dude][idx][pos] = {p, 1 - p};
    valid_prob[dude][idx][pos] = 1;
    return {p, 1 - p};
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> hit[i];
    for (int i = 1; i <= n; i++) cin >> threshold[i];


    dp[(1 << n) - 1] = 1;
    for (int mask = (1 << n) - 1; mask >= 0; mask--) {
        int prev_targ = n - __builtin_popcount(mask);
        int nxt_targ = prev_targ + 1;

        for (int i = 0; i < n; i++) if (mask & (1 << i)) {
            int nmask = mask & ~(1 << i);

            auto [a, _] = calc(i, nxt_targ, 1);
            auto [b, __] = calc(i, nxt_targ, 0);
            

            dp[nmask] = max(dp[nmask], dp[mask] * a + (1 - dp[mask]) * b);
        }
    }

    cout << setprecision(12) << fixed << dp[0] << endl;
}