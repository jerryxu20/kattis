#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair

int solve(int tcase) {
    int n, t, m, a;
    string s;
    cin >> n >> t >> m;

    vector<queue<pii>> cars(2);
    vi ans(m);
    
    for (int i = 0; i < m; i++) {
        cin >> a >> s;
        int idx = s != "left";
        cars[idx].push(mp(a,i));
    }
    
    cars[0].push(mp(100000, -1));
    cars[1].push(mp(100000, -1));

    int time = 0;
    int side = 0;
    
    while(sz(cars[0]) > 1 || sz(cars[1]) > 1) {
        int op = (side + 1) % 2;
        int t1 = cars[side].front().first;
        int t2 = cars[op].front().first;
        if (sz(cars[side]) > 1 && t1 <= max(time, t2)) {
            time = max(time, t1);
        } else if (sz(cars[op]) > 1) {
            time = max(time, t2) + t;
            swap(op, side);
        }
        rep(i, 0, n) {
            if (sz(cars[side]) == 1) break;
            auto car = cars[side].front();
            if (car.first > time) break;
            ans[car.second] = time + t;
            cars[side].pop();
        }
        side = op;
        time += t;
    }
    for (auto &an: ans) {
        cout << an << endl;
    }
    cout << endl;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    return 0;
}