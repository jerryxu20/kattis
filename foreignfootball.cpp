#include <bits/stdc++.h>
using namespace std; 

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(const string& str = "") : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

vector<H> getHashes(string& str, int length) {
	if (sz(str) < length) return {};
	H h = 0, pw = 1;
	rep(i,0,length)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	rep(i,length,sz(str)) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

// 2:13
const int MAXN = 500;

string grid[MAXN][MAXN];
HashInterval HA[MAXN][MAXN];

int main() {
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            HA[i][j] = HashInterval(grid[i][j]);
        }
    }

    int ii = 0, jj = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j) {
            if (sz(grid[i][j]) < sz(grid[ii][jj])) {
                ii = i;
                jj = j;
            }
        }
    }


    int m = sz(grid[ii][jj]);

    vector<H> names(n);
    vector<int> len(n);
    int ans = -1;

    for (int l = 1; l < m; l++) {
        // take the prefix
        H h = HA[ii][jj].hashInterval(0, l);

        len[ii] = l;
        names[ii] = h;

        for (int j = 0; j < n; j++) if (j != ii) {
            // take the suffix of all of these
            names[j] = HA[ii][j].hashInterval(l, sz(grid[ii][j]));
            len[j] = sz(grid[ii][j]) - l;
        }

        int add = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (i != j) {
                if (len[i] + len[j] != sz(grid[i][j])) {
                    add = 0;
                    break;
                }

                int a = len[i];
                int b = len[j];
                if (HA[i][j].hashInterval(0, a).get() != names[i].get()) {
                    add = 0;
                    break;
                }

                if (HA[i][j].hashInterval(a, a + b).get() != names[j].get()) {
                    add = 0;
                    break;
                }
            }
        }

        if (add && ans != -1) {
            cout << "MANY\n";
            return 0;
        }

        if (add) ans = l;
    }

    if (ans == -1) {
        cout << "NONE\n";
        return 0;
    }

    cout << "UNIQUE\n";

    len[ii] = ans;

    vector<string> res(n);
    res[ii] = grid[ii][jj].substr(0, ans);
    for (int j = 0; j < n; j++) if (j != ii) {
        res[j] = grid[ii][j].substr(ans, sz(grid[ii][j]) - ans);
    }

    for (auto &s: res) {
        cout << s << endl;
    }

    
}