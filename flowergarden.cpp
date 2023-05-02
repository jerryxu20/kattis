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

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<bool> is_prime(200005, true);
void sieve() {
    is_prime[1] = false;
    is_prime[0] = true;
    is_prime[2] = true;
    for (ll i = 2; i < 200005; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j < 200005; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return;
}

int solve(int tcase) {
    ll N;
    double D;
    cin >> N >> D;
    ll xx, yy, dx, dy, cnt, ans;
    xx = yy = cnt = ans = 0;
    double dis = 0;
    vector<pll> coord(N);
    for (auto &[a, b]: coord) cin >> a >> b;
    for (auto &[a, b]: coord) {
        dx = xx - a;
        dy = yy - b;
        dis += sqrt((double)dx * dx + (double)dy * dy);
        xx = a;
        yy = b;
        if (dis > D) break;
        cnt++;
        if (is_prime[cnt]) ans = cnt;
    }
    cout << ans << endl;
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    sieve();
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}