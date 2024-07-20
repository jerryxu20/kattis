#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXT = 200;
const int MAXN = 5e4;
typedef long long ll;

int MNDIS[MAXT], MXANGLE[MAXT];
int ANGLE[MAXN], DIS[MAXN];
int LOW[MAXT][MAXN], HIGH[MAXT][MAXN];
ll PREF[MAXN];

const int C = 360000;
const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = min(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return inf;
		if (L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
            mset = x, madd = 0;
            val = min(x, val);
        }
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = min(l->val, r->val);
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

struct Gap {
    map<int, int> delta;
    map<int, int> ans;
    Gap() {};

    void add(int d) {
        if (delta.count(d) || delta.empty()) {
            delta[d]++;
            return;
        }        

        auto it = delta.upper_bound(d);
        if (it == delta.end()) it = delta.begin();

        auto it2 = it;
        if (it == delta.begin()) {
            it2 = delta.end();
        }
        it2--;


        int a = (((it->first - d) % C) + C) % C;
        int b = (((d - it2->first) % C) + C) % C;
        int c = (((it->first - it2->first) % C) + C) % C;

        ans[a]++;
        ans[b]++;
        ans[c]--;
        if (ans[c] == 0) ans.erase(c);

        delta[d]++;
    }

    void erase(int d) {
        delta[d]--;
        if (delta[d] > 0) return;
        delta.erase(d);
        if (delta.empty()) return;
        auto it = delta.upper_bound(d);
        if (it == delta.end()) it = delta.begin();

        auto it2 = it;
        if (it == delta.begin()) {
            it2 = delta.end();
        }
        it2--;


        int a = (((it->first - d) % C) + C) % C;
        int b = (((d - it2->first) % C) + C) % C;
        int c = (((it->first - it2->first) % C) + C) % C;

        ans[a]--;
        ans[b]--;
        ans[c]++;
        
        if (ans[a] == 0) ans.erase(a);
        if (ans[b] == 0) ans.erase(b);
    }

    int query() {
        ans.erase(0);
        if (ans.size() == 0) return 0;
        return C - ans.rbegin()->first;
    }
};

int main() {
    int t, n; cin >> t >> n;

    for (int i = 0; i < t; i++) {
        cin >> MNDIS[i] >> MXANGLE[i];
    }

    set<int> st;
    for (int i = 1; i < n; i++) {
        cin >> DIS[i] >> ANGLE[i];
        ANGLE[i] += ANGLE[i - 1];
        ANGLE[i] = ((ANGLE[i] % C) + C) % C; 
        st.insert(ANGLE[i]);
    }

    memset(LOW, -1, sizeof(LOW));
    memset(HIGH, -1, sizeof(HIGH));

    for (int i = 0; i < t; i++) {
        int low = 0;
        ll dis = 0;
        Gap g;
        for (int j = 1; j < n; j++) {
            dis += DIS[j];
            g.add(ANGLE[j]);

            while(g.query() > MXANGLE[i] && low < j) {
                g.erase(ANGLE[low + 1]);
                dis -= DIS[low + 1];
                low++;
            }

            while(dis >= MNDIS[i] && low < j) {
                LOW[i][low] = j;
                HIGH[i][low] = j;
                dis -= DIS[low + 1];
                g.erase(ANGLE[low + 1]);
                low++;
            }
        }
    }

    for (int i = 0; i < t; i++) {
        int low = 0;
        ll dis = 0;
        Gap g;
        for (int j = 1; j < n; j++) {
            g.add(ANGLE[j]);

            while(g.query() > MXANGLE[i] && dis >= MNDIS[i]) {
                HIGH[i][low] = j - 1;
                dis -= DIS[low + 1];
                g.erase(ANGLE[low + 1]);
                low++;
            }

            while(g.query() > MXANGLE[i]) {
                g.erase(ANGLE[low + 1]);
                dis -= DIS[low + 1];
                low++;
            }
            dis += DIS[j];
        }

        while(low < n && g.query() <= MXANGLE[i] && dis >= MNDIS[i]) {
            HIGH[i][low] = n - 1;
            dis -= DIS[low + 1];
            low++;
        }
    }

    vector<int> DP(n, INT_MAX);
    DP[0] = 0;

    typedef pair<int, int> pi;
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    vector<vector<pi>> add(n);
    for (int i = 0; i < n; i++) {

        for (auto &p: add[i]) pq.push(p);

        while(pq.size() && pq.top().second < i) {
            pq.pop();
        }

        if (pq.size()) DP[i] = min(DP[i], pq.top().first);
        if (DP[i] == INT_MAX) continue;

        int d = DP[i];
        for (int j = 0; j < t; j++) {
            if (LOW[j][i] == -1) continue;
            add[LOW[j][i]].push_back({d + 1, HIGH[j][i]});
        }
    }

    if (DP.back() == INT_MAX) {
        cout << "IMPOSSIBLE\n";
        return 0;
    } 

    cout << DP.back() << endl;
}