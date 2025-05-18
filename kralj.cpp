#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> chosen(n);
    for (int &x: chosen) {
        cin >> x; x--;
    }
    
    vector<int> opps(n), elves(n);
    for (int &x: opps) cin >> x;
    for (int &x: elves) cin >> x;

    vector<int> cnt(n);
    for (int &idx: chosen) cnt[idx]++;

    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
    }

    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        cnt[i] -= i;
        mn = min(mn, cnt[i]);
    }

    int s = -1;
    for (int i = 0; i < n; i++) if (cnt[i] == mn) {
        s = i;
        break;
    }

    assert(s != -1);
    s = (s + 1) % n;

    vector<vector<int>> at(n);
    for (int i = 0; i < n; i++) {
        at[chosen[i]].push_back(elves[i]);
    }

    int ans = 0;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int idx = (s + i) % n;
        for (int &p: at[idx]) {
            st.insert(p);
        }

        int opp = opps[idx];
        
        // choose weakers that beats opp or sack the weakest
        assert(st.size());
        auto it = st.lower_bound(opp);
        if (it == st.end()) {
            st.erase(st.begin());
        } else {
            ans++;
            st.erase(it);
        }
    }

    cout << ans << endl;
}