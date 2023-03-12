#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int J, R, D, A, B;
double eps = 10e-8;

double distance(pii &a, pii &b) {
    ll dx = abs(a.first - b.first);
    ll dy = abs(a.second - b.second);
    return sqrt(dx * dx + dy * dy);
}

double angle(pii a, pii b) {
    if (a == b) return 0;
    a.first *= -1;
    a.second *= -1;
    if (a.first == 0 && a.second == 0) return 0;
    ll dot = (ll)a.first * (ll)b.first + (ll)a.second * (ll)b.second;
    ll maga = (ll)a.first * (ll)a.first + (ll)a.second * (ll)a.second;
    ll magb = (ll)b.first * (ll)b.first + (ll)b.second * (ll)b.second;
    double frac = (double) dot / (sqrt(maga) * sqrt(magb));
    return -frac;
}

bool possible(double mid, vector<vi> &adj, vector<pii> &coords) {
    double target = cos(mid * M_PI / 180);
    // cout << mid << " " << target << endl;
    vector<vector<double>> ans(J + 1, vector<double>(J+1, 1e9));
    priority_queue<tuple<double, int, int>> pq;
    pq.push({0, 1, 1});
    ll dx, dy;
    while(!pq.empty()) {
        auto [cost, node, prev] = pq.top();
        pq.pop();
        if (cost > D) return false;
        if (node == J) return true;
        if (cost > ans[node][prev]) continue;
        for (auto &nxt: adj[node]) {
            double ncost = cost + distance(coords[node], coords[nxt]);
            if (ans[nxt][node] <= ncost) continue;
            pair<ll, ll> dir, ndir;
            dx = (ll)coords[nxt].first - coords[node].first;
            dy = (ll)coords[nxt].second - coords[node].second;
            dir = mp(dx, dy);
            dx = (ll)coords[node].first - coords[prev].first;
            dy = (ll)coords[node].second - coords[prev].second;
            ndir = mp(dx, dy);
            // cout << angle(dir, ndir) << " " << target << endl;
            // cout << "angle " << angle(dir, ndir) << " target " << target << endl;
            if (angle(dir, ndir) < target) continue;
            ans[nxt][node] = ncost;
            pq.push({ncost, nxt, node}); 
        }
    }
    return false;
}

int main() {
    cin >> J >> R >> D;
    vector<vi> adj(J + 1);
    vector<pii> coords(J + 1);
    for (int i = 1; i <= J; i++) {
        cin >> coords[i].first >> coords[i].second;
    }
    while(R--) {
        cin >> A >> B;
        adj[A].pb(B);
    }
    double low = 0;
    double high = 180;
    double ans = 700;
    while (high - low > eps) {
        double mid = (low + high) / 2;
        if (possible(mid, adj, coords)) {
            ans = min(ans, mid);
            high = mid;
        } else {
            low = mid;
        }
    }
    if (ans > 360) {
        cout << "Impossible\n";
        return 0;
    }
    cout << setprecision(20) << fixed <<  ans << endl;
    return 0;
}