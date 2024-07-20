#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

const int MOD = 1e9 + 7;
const int MAXN = 501;
const int MAXH = 1e6 + 1;
ll dp[MAXN][MAXN][MAXN];
ll fac[MAXH], inv[MAXH];

vector<int> height;
int n, k;

ll choose(int n, int k) {
    if (n < k) return 0;
    ll ans = (fac[n] * inv[k]) % MOD * inv[n - k];
    return (ans % MOD);
}

void f(int i, int j, RMQ<int> &mn) {
    int high = mn.query(i, j + 1);
    int low = 0;
    if (i > 0) low = max(low, height[i - 1]);
    if (j + 1 < n) low = max(low, height[j + 1]);
    
    int w = j - i + 1;
    int h = high - low;

    vector<pair<int, int>> parts;

    low = i;
    for (int idx = i; idx <= j; idx++) {
        if (height[idx] == high) {
            if (low < idx) parts.push_back({low, idx - 1});  
            low = idx + 1;
        }
    } 
    if (low <= j) {
        parts.push_back({low, j});
    }


    vector<ll> other(MAXN);
    other[0] = 1;

    for (auto &[ii, jj]: parts) {
        f(ii, jj, mn);
        for (int x = k; x >= 0; x--) {
            for (int y = 1; y <= k; y++) if (x + y <= k) {
                other[x + y] += other[x] * dp[ii][jj][y];
                other[x + y] %= MOD;
            }
        }
    }

    for (int x = k; x >= 0; x--) {
        for (int y = 0; y <= k; y++) if (x + y <= k) {
            ll cur = (choose(w - y, x) * choose(h, x)) % MOD;            
            cur *= fac[x];
            cur %= MOD;
            dp[i][j][x + y] += other[y] * cur;
            dp[i][j][x + y] %= MOD;
        }
    }

}

ll power(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res *= a;
        a *= a;
        b /= 2;

        res %= MOD;
        a %= MOD;
    }
    return res;
}


int main() {
    fac[0] = 1;
    ll cur = 1;
    for (int i = 1; i < MAXH; i++) {
        cur = (cur * i) % MOD;
        fac[i] = cur;
    }

    for (int i = 0; i < MAXH; i++) {
        inv[i] = power(fac[i], MOD - 2);
    }
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        height.push_back(h);
    }
    RMQ<int> mn(height);
    f(0, n - 1, mn);

    cout << dp[0][n - 1][k] << endl;
}