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
// ask what is the longest common prefix of these two words?



vector<vector<int>> nxt(1, vector<int>(26));
vector<int> id(1, -1);
int N = 0;

const int MAXN = 1e5;
string dict[MAXN];
HashInterval H[MAXN];

int lcp(HashInterval &a, HashInterval &b) {
    int low = 1;
    int high = min(sz(a.ha) - 1, sz(b.ha) - 1);
    int ans = 1;

    while(low <= high) {
        int mid = (low + high)/2;
        if (a.hashInterval(0, mid) == b.hashInterval(0, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}


int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> dict[i];
        H[i] = HashInterval(dict[i]);

        int node = 0;
        for (int j = 0; j < sz(dict[i]); j++) {
            int idx = dict[i][j] - 'a';
            if (nxt[node][idx] == 0) {
                nxt[node][idx] = ++N;
                nxt.push_back(vector<int>(26));
                id.push_back(i);
            }

            node = nxt[node][idx];
        }
    }


    while(m--) {
        string s; cin >> s;
        vector<int> dp(sz(s), sz(s));
        dp[0] = 1;

        HashInterval HA(s);

        int node = 0;
        for (int i = 0; i < sz(s) - 1; i++) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);

            int idx = s[i] - 'a';
            if (nxt[node][idx] == 0) break;

            node = nxt[node][idx];
            int x = id[node];
            int l = lcp(HA, H[x]);
            int r = sz(dict[x]) - l;
            dp[l - 1] = min(dp[l - 1], dp[i] + 1 + r);

        }

        for (int i = 1; i < sz(s); i++) {
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }

        cout << dp.back() << endl;
    }
}