#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128_t ull;
ll sm = 0;
ll n, c;
vector<tuple<int, int, int>> arr;
bool valid(ll x) {
    // we have x days. 
    vector<int> uses(n), used(sz(arr));
    ull units = (ull)(x - 1) * c;
    ull covered = 0;

    int idx = 0;
    for (auto &[w, cnt, id]: arr) {
        if (w == 0) break;
        ull cap = min({(ull)cnt, (ull)(x - 1) - uses[id], units});
        uses[id] += cap;
        used[idx++] = cap;
        units -= cap;
        covered += w * cap;
    }

    units = c;
    idx = 0;
    for (auto &[w, cnt, id]: arr) {
        if (w == 0) break;
        ull cap = min({(ull)cnt - used[idx], (ull)x - uses[id], units});
        idx++;
        units -= cap;
        uses[id] += cap;
        covered += w * cap;
    }

    return (sm - covered) <= units;
}

int main() {
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int t, d; cin >> t >> d;

        arr.push_back({d, t/d, i});
        arr.push_back({t % d, 1, i});
        sm += t;
    }

    sort(all(arr));
    reverse(all(arr));

    ll low = 1;
    ll high = 1e18;
    ll ans = -1;
    while(low <= high) {
        ll mid = (low + high)/2;
        if (valid(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans - 1 << endl;
}