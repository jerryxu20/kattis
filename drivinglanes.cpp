#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, m; cin >> n >> m;
    ll k, r; cin >> k >> r;

    vector<ll> len(n);
    for (ll &x: len) cin >> x;

    typedef pair<ll, ll> pi;
    vector<pi> curves(n - 1);
    for (auto &[s, c]: curves) {
        cin >> s >> c;
    }


    typedef tuple<ll, ll, ll> ti;
    priority_queue<ti, vector<ti>, greater<ti>> pq;


    vector<vector<ll>> dis(n + 2, vector<ll>(m + 2, LLONG_MAX));
    dis[0][1] = 0;

    pq.push({0, 0, 1});
    
    while(pq.size()) {
        auto [d, track, lane] = pq.top();
        pq.pop();
        if (track == n && lane == 1) {
            cout << d << endl;
            return 0;
        }
        if (track == n) continue;
        if (dis[track][lane] != d) continue;

        for (int nlane = 1; nlane <= m; nlane++) {
            ll span = k * abs(lane - nlane);
            if (span > len[track]) continue;

            ll curved_dis = 0;
            ll track_dis = 0;
            if (track < n - 1) {
                auto [s, c] = curves[track];
                curved_dis = s + c * nlane;
            } 
           
            ll cand = d + r * abs(lane - nlane) + len[track] + curved_dis;
            if (cand < dis[track + 1][nlane]) {
                pq.push({cand, track + 1, nlane});
                dis[track + 1][nlane] = cand;
            }
        }
    }

}