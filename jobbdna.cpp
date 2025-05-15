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

int count_disjoint(int mn, vector<int> &idx) {
    int ans = 0;
    int right = -1;
    for (auto &i: idx) if (i >= mn) {
        if (i >= right) {
            ans++;
            right = i + m;
        } 
    }
    return ans;
}

struct SuffixArray {
	vi sa, lcp, at;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);

        at.resize(n);
        rep(i, 1, n) {
            at[sa[i]] = i; 
        }
	}
};

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

int smaller(int i, int j, SuffixArray &sa) {
    i = sa.at[i];
    j = sa.at[j];
    return i < j;
}

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

const int MAXN = 2e6;
const int B = 1000;
int n, m;
vi at[MAXN];
int cnt[MAXN], arr[MAXN], low[MAXN];

int main() {
    cin >> n >> m;
    string s; cin >> s;

    s += s;
    vector<H> strs = getHashes(s, m);
    SuffixArray sa(s);

    map<H, int> id, freq;

    for (auto &h: strs) freq[h]++;

    int N = 0;
    vector<Node> seg;
    for (auto &h: strs) if (freq[h] >= B && !id.count(h)) {
        id[h] = N++;
        seg.push_back(Node(0, n + n));
    }
    for (auto &h: strs) if (!id.count(h)) {
        id[h] = N++;
    }
    
    for (int i = 0; i < sz(strs); i++) {
        arr[i] = id[strs[i]];
        cnt[arr[i]]++;
    }

    int right = m - 1;
    int left = 0;
    int best = 0;
    int ans = -1;

    for (int i = 0; i < sz(strs); i++) {
        int x = arr[i];
        if (right >= n && cnt[arr[left - 1]] >= B) {
            int rem = arr[left - 1];
            seg[rem].add(left - 1 + m, n + n, -1);

            int &j = low[rem];
			assert(at[rem][j] == left - 1);

            j++;
            if (j < sz(at[rem]) && left - 1 + m > at[rem][j]) {
                seg[rem].add(at[rem][j] + m, n + n, 1);
            }

        }
        at[x].push_back(i);
        if (cnt[x] < B) {
            int cand = count_disjoint(left, at[x]);
			assert(cand > 0);
            if (cand > best || (cand == best && smaller(i, ans, sa))) {
                best = cand;
                ans = i;
            }
        } else {
			assert(x < sz(seg));
            int cand = max(0, seg[x].query(left, i - m + 1)) + 1;
            seg[x].set(i, i + 1, cand);
            if (cand > best || (cand == best && smaller(i, ans, sa))) {
                best = cand;
                ans = i;
            }
        }

        right++;
		if (right >= n) {
			left++;
		}
    }

    assert(ans != -1);
    cout << s.substr(ans, m) << endl;
}