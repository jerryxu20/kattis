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

int main() {
    int L1, L2, n;
    cin >> L1 >> L2 >> n;
    vector<pii> tube(n);
    int idx = 0;
    for (auto &[t, i]: tube) {
        cin >> t;
        i = idx++;
        t *= -1;
    }
    set<pii> st(all(tube));
    int ans = -1;
    for (auto &[tube1, i]: tube) {
        int want = -L1 - tube1;
        st.erase(tube[i]);
        auto it = st.lower_bound(mp(want, -1));
        if (it != st.end()) {
            auto [tube11, ii]  = *it;
            st.erase(it);
            for (auto &[tube2, j]: tube) {
                if (j == i || j == ii) continue;
                st.erase(tube[j]);
                want = -L2 - tube2;
                auto it2 = st.lower_bound(mp(want, -1));
                if (it2 != st.end()) {
                    auto &[tube22, jj] = *it2;
                    ans = max(ans, -(tube1 + tube2 + tube11 + tube22));
                }
                st.insert(tube[j]);
            }
            st.insert(mp(tube11, ii));
        }
        st.insert(tube[i]);
    }
    if (ans == -1) {
        cout << "Impossible\n"; 
    } else {
        cout << ans << endl;
    }
    return 0;
}