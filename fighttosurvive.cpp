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

int solve(int tt) {
    int S, m;
    cin >> S >> m;


    PQ<pi> good;
    PQ<int> med;
    queue<int> bad;
    queue<pi> prev;
    while(S--) {
        int h; cin >> h;
        good.push({h, h});
    }

    int e; cin >> e;
    int timer = 0;
    while(e--) {
        if (timer % m == m - 1) {
            if (sz(med)) {
                int health = med.top();
                good.push({health/2, health});
                med.pop();
            }
        }
        string s; cin >> s;
        int p = sz(prev);
        if (s == "ATTACK") {
            auto x = bad.front();
            bad.pop();


            while(sz(good) && x > 0) {
                auto [have, og] = good.top();
                good.pop();

                int cap = min(have, x);
                x -= cap;
                have -= cap;


                if (have) {
                    prev.push({have, og});
                } else {
                    med.push(og);
                }
            }

            if (x > 0) {
                cout << "overrun" << endl;
                return 0;
            }

        } else {
            int x; cin >> x;
            bad.push(x);
        }

        while(p--) {
            good.push(prev.front());
            prev.pop();
        }
        timer++;
    }

    cout << "success" << endl;




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