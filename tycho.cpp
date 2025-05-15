#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1LL << 60;
struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, mset = inf, madd = 0, val = inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = min(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return inf;
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = min(l->val, r->val);
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = min(l->val, r->val);
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

int main() {
	ll b, p, d, n; cin >> b >> p >> d >> n;
    vector<ll> shelter(n);
    for (ll &x: shelter) cin >> x;

	shelter.push_back(0);
	sort(all(shelter));
	n++;
    
    vector<ll> mod;
    for (ll &x: shelter) mod.push_back(x % p);
    sort(mod.begin(), mod.end());

    map<ll, int> mod_start, mod_end;
    for (int i = n - 1; i >= 0; i--) {
        mod_start[mod[i]] = i;
    }
	for (int i = 0; i < n; i++) {
		mod_end[mod[i]] = i;
	}
	mod.push_back(LLONG_MAX);

	vector<int> idx(n);
    iota(all(idx), 0);
	sort(all(idx), [&] (auto &x, auto &y) {
		if (shelter[x] % p == shelter[y] % p) return shelter[x] < shelter[y];
		return (shelter[x] % p) < (shelter[y] % p);
	});

	vector<int> at(n);
	for (int i = 0; i < n; i++) {
		at[idx[i]] = i;
	}

	Node seg(0, n);
	seg.set(0, 1, 0);
    auto rotate = [&] (ll mod_a, ll mod_b, Node &seg) {
        int sign = 1;
        if (mod_a > mod_b) {
            swap(mod_a, mod_b);
            sign = -1;
        }
        ll delta = mod_b - mod_a;
        
		int a = mod_start[mod_a];
		int b = mod_start[mod_b];
		int aa = mod_end[mod_a];
		int bb = mod_end[mod_b];
        seg.add(b, seg.hi, sign * -delta);
        seg.add(0, a, sign * -delta);
        seg.add(a, b, sign * (p - delta));

    };
	auto pulse = [&] (ll mod_a, ll mod_b, ll cnt, Node &seg, auto &f) -> void {
		if (mod_b < mod_a) {
			f(mod_a, p - 1, cnt, seg, f);
			f(0, mod_b, cnt, seg, f);
			return;
		} 
		
		int a = lower_bound(all(mod), mod_a) - mod.begin();
		int b = upper_bound(all(mod), mod_b) - mod.begin();
		seg.add(a, b, cnt * d);
 	};
	
	
	ll ans = ((b - 1)/p - (count(all(mod), 0) - 1)) * d + b; 
	
	for (int i = 1; i < n; i++) {
		rotate(shelter[i - 1] % p, shelter[i] % p, seg);

		ll delta = shelter[i] - shelter[i - 1];
		seg.add(0, seg.hi, delta);


		ll wall = max(0LL, shelter[i - 1] - p + 1);
	
		// wall, x, shelter[i]
		// between wall and x there are cnt + 1 shocks
		// between x and shelter there are cnt shocks
		ll shocks = (delta - 1)/p;
		assert((shelter[i] - wall - 1)/p <= shocks + 1);
		if ((shelter[i] - wall - 1)/p == shocks + 1) {
			ll x = shelter[i] - p * (shocks + 1) - 1;
			// assert((shelter[i] - x - 1)/p == shocks + 1);
			// assert((shelter[i] - (x + 1) - 1)/p == shocks);

			ll a = wall % p;
			ll b = x % p;
			ll c = shelter[i - 1] % p;

			// for mods b -> c, not including b, add shocks
			// for mods a -> b, add shocks + 1
			pulse(a, b, shocks + 1, seg, pulse);
			pulse((b + 1) % p, c, shocks, seg, pulse);
		
		} else {
			ll a = wall % p;
			ll b = shelter[i - 1] % p;
			pulse(a, b, shocks, seg, pulse);
		}


		ll cur = seg.query(0, seg.hi);
		seg.set(at[i], at[i] + 1, cur);
		
		// continue to end from here
		int last_idx = upper_bound(all(mod), shelter[i] % p) - mod.begin();
		ll dodges = last_idx - at[i] - 1;
		ll shocked = (b - shelter[i] - 1)/p;

		ll cand = cur + (shocked - dodges) * d + (b - shelter[i]);
		ans = min(ans, cand);
	}

	cout << ans << endl;

}