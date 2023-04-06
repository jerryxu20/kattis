#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair


int solve() {
    int G, M;
    cin >> G >> M;
    vi zilla(G);
    vi mecha(M);
    for (auto &x: zilla) cin >> x;
    for (auto &x: mecha) cin >> x;
    priority_queue<int> z(all(zilla));
    priority_queue<int> m(all(mecha));
    while(sz(z) && sz(m)) {
        if (m.top() <= z.top()) {
            m.pop();
        } else {
            z.pop();
        }
    }
    if (sz(z)) {
        cout << "Godzilla\n";
    } else {
        cout << "MechaGodzilla\n";
    }

    return 0;
}

int main() {
    int tcase = 1;
    cin >> tcase;
    for (int i = 1; i <= tcase; i++) {
        // cout << "Case #" << i << " : ";
        solve();
    }
    return 0;
}