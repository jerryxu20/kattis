#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()



int main() {
    int n; cin >> n;

    queue<string> q;
    q.push(string(10, 'a'));

    unordered_set<string> seen;

    vector<string> ans = {string(10, 'a')};

    seen.insert(ans[0]);

    while(sz(ans) < n) {
        string prev = ans.back();

        bool found = false;
        for (auto &c: prev) {
            char og = c;
            for (char nxt = 'a'; nxt <= 'z'; nxt++) if (nxt != og) {
                c = nxt;
                if (seen.count(prev)) continue;

                if (found == false) {
                    // cout << prev << endl;
                    found = true;
                    ans.push_back(prev);
                }
                seen.insert(prev);
            }
            c = og;
        }

        assert(found);
    }

    for (auto &s: ans) {
        cout << s << endl;
    }


}