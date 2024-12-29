#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int N = 0;
map<string, int> ID;
int id(string &s) {
    if(ID.count(s)) return ID[s];
    ID[s] = N++;
    return ID[s];
}

vector<ll> P = {(ll)2e9 + 11, 8675309};

vector<int> parse(string &s) {
    int f = 1;
    int k = 1;
    string token = "";
    vector<int> weight(100);
    s += ' ';
    for (char &c: s) {
        if (c == '=') {
            f *= -1;
            k = 1;
            continue;
        }
        if (c == ' ') {
            if (sz(token) && token != "1") {
                int x = id(token);
                weight[x] += f * k;
            }
            token = "";
            continue;
        }
        if (c == '*') {
            k = 1;
            continue;
        }

        if (c == '/') {
            k = -1;
            continue;
        }

        token.push_back(c);
    }
    return weight;
}

typedef vector<ll> vd;
const ll eps = 0;

ll power(ll a, ll b, ll mod) {
    ll ans = 1;
    while(b) {
        if (b & 1) ans *= a;
        a *= a;
        b /= 2;

        a %= mod;
        ans %= mod;
    }
    return ans;
}

int solveLinear(vector<vd> A, vd& b, vd& x, ll mod) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vector<ll> col(m); iota(all(col), 0);

	rep(i,0,n) {
		ll v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = abs(A[r][c])) > bv)
				br = r, bc = c, bv = v;
		if (bv <= eps) {
			rep(j,i,n) if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
        bv = power(A[i][i], mod - 2, mod);
		rep(j,i+1,n) {
			ll fac = A[j][i] * bv;
            fac %= mod;
			b[j] -= fac * b[i];
            b[j] %= mod;
			rep(k,i+1,m) {
                A[j][k] -= fac*A[i][k];
                A[j][k] %= mod;
            }
		}
		rank++;
	}
    return 1;
}

int main() {
    int n; cin >> n;
    string s;
    vector<vi> arr(100, vi(100));
    getline(cin, s);
    rep(i, 0, n) {
        getline(cin, s);
        arr[i] = parse(s);
        int x = count(all(arr[i]), 0);
    }

    // A * x = b
    vector<vd> A(100, vd(100));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            A[j][i] = arr[i][j];
        }
    }

    for (ll p: P) {
        rep(i, 0, N) {
            vd B(100);
            B[i] = 1;

            vd x(100);
            if (solveLinear(A, B, x, p) != -1) {
                cout << "invalid\n";
                return 0;
            }
        }
    }

    cout << "valid\n";
}