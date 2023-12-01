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
int p, n;
vi ans, car;
vpi at;
void pick(PQG<ti> &pq, vector<int> &gas, queue<int> &q, int time, int i) {
    auto nxt = q.front();
    q.pop();
    // go to B if it's free
    if (gas[1] == 0) {
        gas[1] = 1;
        at[nxt] = {i, 1};
    } else {
        gas[0] = 1;
        at[nxt] = {i, 0};
    }
    pq.push({time + car[nxt], 0, nxt});
    return;
}

void place(vector<queue<int>> &lines, int node) {
    int choice = 0;
    rep(i, 0, p) {
        if (sz(lines[i]) < sz(lines[choice])) {
            choice = i;
        }
    }
    lines[choice].push(node);
    return;
}

void solve(PQG<ti> &pq) {
    vii gas(p, vi(2));
    vector<queue<int>> q(p);
    while(sz(pq)) {
        auto [time, type, node] = pq.top();
        pq.pop();
        if (type == 0) {
            auto [i, j] = at[node];
            gas[i][j] = 0;
            ans[node] = time;
            while(gas[i][0] ==  0 && sz(q[i])) {
                pick(pq, gas[i], q[i], time, i);
            }
            continue;
        }
        // a car is arriving
        bool found = false;
        rep(i, 0, p) {
            if (gas[i][0] == 0) {
                assert(sz(q[i]) == 0);
                q[i].push(node);
                pick(pq, gas[i], q[i], time, i);
                found = true;
                break;
            }
        }
        if (found) continue;
        place(q, node);        
    }
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> p >> n;
    ans.resize(n);
    at.resize(n);
    PQG<ti> left, right;
    rep(i, 0, n) {
        int time, fill;
        char side;
        cin >> time >> fill >> side;
        if (side == 'R') {
            right.push({time, 1, i});
        } else {
            left.push({time, 1, i});
        }
        car.pb(fill);
    }
    solve(left);
    solve(right);
    rep(i, 0, n) {
        cout << ans[i] << nl;
    }
    return 0;
}