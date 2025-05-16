#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;

typedef long long ll;
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()

typedef uint64_t ull;
static int C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() const { return x ^ (ull) b << 21; }
    ull get() {return (ull)*this; }
	bool operator==(A o) const { return (ull)*this == (ull)o; }
	bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};


int main() {
	timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)
	assert((ull)(H(1)*2+1-3) == 0);

    int n; cin >> n;
    vector<string> str(n);
    for (auto &s: str) cin >> s;
    
    auto strip = [] (string &s) {
        string ans;
        for (char &c: s) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') continue;
            ans.push_back(c);
        }
        return ans;
    };
    
    vector<string> stripped;
    for (auto &s: str) stripped.push_back(strip(s));

    set<int> st;
    for (auto &s: stripped) st.insert(s.size());
    vector<int> arr(st.begin(), st.end());
    
    map<ull, int> hashes;
    for (int i = 0; i < n; i++) {
        ull h = HashInterval(stripped[i]).hashInterval(0, sz(stripped[i])).get();
        if (!hashes.count(h) || sz(str[i]) - sz(stripped[i]) > sz(str[hashes[h]]) - sz(stripped[hashes[h]]) ) {
            hashes[h] = i;
        }
    }

    string t; cin >> t;
    HashInterval ha(t);

    vector<int> dp(sz(t) + 1, -1), par(sz(t) + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= sz(t); i++) if (dp[i - 1] != -1) {
        for (auto &len: arr) {
            if (i + len - 1 > sz(t)) break;
            int l = i - 1;
            int r = i + len - 1;

            ull h = ha.hashInterval(l, r).get();
            if (hashes.count(h)) {
                int idx = hashes[h];
                int vcount = sz(str[idx]) - sz(stripped[idx]);
                int cand = dp[i - 1] + vcount;
                if (cand > dp[r]) {
                    dp[r] = cand;
                    par[r] = idx;
                }
            } 
        }
    }

    assert(dp[sz(t)] != -1);


    vector<int> ans;
    int node = sz(t);
    while(par[node] != -1) {
        int idx = par[node];
        ans.push_back(idx);

        node -= sz(stripped[idx]);
    }

    for (int i = sz(ans) - 1; i >= 0; i--) {
        cout << str[ans[i]] << " ";
    }
    cout << endl;



}