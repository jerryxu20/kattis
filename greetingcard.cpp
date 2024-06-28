#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

int main() {
    int targ = 2018 * 2018;

    vector<pl> delta;

    for (int i = 0; i <= 2018; i++) {
        int need = targ - i * i;

        int x = sqrt(need);
        if (x * x == need) {
            delta.push_back({i, x});
            if (i > 0 && x > 0) delta.push_back({-i, x});
        }
    }

    int n; cin >> n;

    vector<pl> pts;    
    while(n--) {
        int a, b; cin >> a >> b;
        pts.push_back({a, b});
    }
    set<pl> st(pts.begin(), pts.end());

    int ans = 0;
    for (auto &[x, y]: pts) {
        ll xx, yy;
        for (auto &[a, b]: delta) {
            xx = x + a;
            yy = y + b;

            if (st.count({xx, yy})) ans++;
            
        }
    }

    cout << ans << endl;


    
}