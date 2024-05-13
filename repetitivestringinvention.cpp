#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;
typedef tuple<int,int,int> ti;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vii;
typedef vector<vii> viii;

template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for (int i=a; i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(x,A) for (auto& x : A)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

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
    HashInterval(string &str) : ha(sz(str) + 1), pw(ha) {
        pw[0] = 1;
        rep(i, 0, sz(str)) {
            ha[i + 1] = ha[i] * C + str[i];
            pw[i + 1] = pw[i] * C;
        }
    }
    H hashInterval(int a, int b) {
        return ha[b] - ha[a] * pw[b - a];
    }
};

struct Trie {
    vii nxt;
    vi cnt;
    int N = 0;
    Trie() {
        nxt.resize(1, vi(26));
        cnt.resize(1);
    }

    void add(string &s, int i, int j) {
        int node = 0;

        while(j >= i) {
            int idx = s[j] - 'a';
            if (nxt[node][idx] == 0) {
                nxt.pb(vi(26));
                cnt.pb(0);
                nxt[node][idx] = ++N;
            }
            node = nxt[node][idx];
            cnt[node]++;
            j--;
        }
    }
};


vi Z(const string& S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

ll helper(string &s) {
    int n = sz(s);
    ll ans = 0;
    // cout << "help\n";
    Trie trie;

    rep(i, 0, n) {
        // add in i - 1
        if (i > 1) { 
            trie.add(s, 0, i - 2);  
        }

        string sub = s.substr(i);
        vi match = Z(sub);

        rep(k, 2, sz(match)) {
            // match[i] is how far it matches start of sub
            if (match[k] == 0) continue;

            ll suffcnt = min(k - 1, match[k]); // the number of suffixes that work
            int wait = k - 1 - suffcnt;

            // walk through the suffixes, if its too small continue
            int node = 0;
            FORd(j, i + 1, i + k) {
                int idx = s[j] - 'a';
                if (trie.nxt[node][idx] == 0) break;
                node = trie.nxt[node][idx];

                if (wait == 0) {
                    ans += trie.cnt[node];
                }
                else {
                    wait--;
                }
            }   
        }   
    }
    return ans;
}

int solve(int tt) {
    string s; cin >> s;
    int n = sz(s);

    ll ans = 0;

    unordered_map<ull, int> cnt;
    HashInterval H(s);

    rep(i, 0, n) {
        rep(k, 0, i - 1) {
            ull x = H.hashInterval(k, i - 1).get();
            cnt[x]++;
        }

        rep(j, i, n) {
            ull x = H.hashInterval(i, j + 1).get();
            ans += cnt[x];
            int len = j - i + 1;
            if (len % 2 == 0) {
                ull a = H.hashInterval(i, i + len/2).get();
                ull b = H.hashInterval(i + len/2, j + 1).get();
                if (a == b) {
                    ans += (len - 1);
                }
            }
        }
    }

    ans += helper(s);
    reverse(all(s));
    ans += helper(s);

    cout << ans << nl;


    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}