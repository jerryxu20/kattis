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

vii events;
int m, p;
bool work(bool weekends = false) {
    PQG<int> pq;

    rep(i, 0, 101) {
        trav(e, events[i]) {
            pq.push(e);
        }

        if (!weekends && (i % 7 == 0 || i % 7 == 6)) continue;

        if (sz(pq) && pq.top() < i) return false;

        int j = p;
        while(sz(pq) && pq.top() >= i && j--) {
            pq.pop();
        }
    }

    return sz(pq) == 0;
}


int solve(int tt) {
    cin >> m >> p;
    p/=2;
    events.assign(101, {});

    while(m--) {
        int a, b;
        cin >> a >> b;
        events[a].pb(b);
    }

    if (p == 0) {
        cout << "serious trouble\n";
        return 0;
    }

    if (work()) {
        cout << "fine\n";
        return 0;
    }
    if (work(true)) {
        cout << "weekend work\n";
        return 0;
    }
    cout << "serious trouble\n";

    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}