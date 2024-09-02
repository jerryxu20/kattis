#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll read() {
    string s; cin >> s;

    int idx = find(s.begin(), s.end(), '.') - s.begin();
    if (idx == (int) s.size()) {
        return stoi(s) * 1000;
    }

    string a = s.substr(0, idx);
    string b = s.substr(idx + 1, (int)s.size() - idx - 1);
    while(b.size() < 3) b += '0';
    return stoi(a) * 1000 + stoi(b);
}

typedef pair<ll, ll> pi;
ll d2(pi &a, pi &b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}

void solve() {
    ll x, y, w, h, r;
    x = read(), y = read(), w = read(), h = read(), r = read();

    vector<pi> circs = {{x + r, y + r}, {x + r, y + h - r}, {x + w - r, y + r}, {x + w - r, y + h - r}};


    int m; cin >> m;
    while(m--) {
        pi pt;
        pt.first = read();
        pt.second = read();

        bool hit = false;
        for (auto &c: circs) {
            ll d = d2(pt, c);
            if (d <= r * r) hit = true;
        }

        if (x + r <= pt.first && pt.first <= x + w - r && y <= pt.second && pt.second <= y + h) {
            hit = true;
        }

        if (y + r <= pt.second && pt.second <= y + h - r && x <= pt.first && pt.first <= x + w) {
            hit = true;
        }

        if (hit) {
            cout << "inside\n";
        } else {
            cout << "outside\n";
        }
    } 
    cout << endl;
}


int main() {
    int n; cin >> n;
    while(n--) solve();
}