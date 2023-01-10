#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

void backtrack(int i, int cost, string &s, set<string> &made, int &ans, vector<int> &costs) {
    if (i == (int)s.length()) {
        ans = min(ans, cost);
    }
    string cover = "";
    for (;i < (int) s.length(); i++) {
        cover += s[i];
        if (made.count(cover)) {
            // we will use this
            backtrack(i + 1, cost, s, made, ans, costs);
        } else {
            made.insert(cover);
            backtrack(i + 1, cost + costs[(int)cover.length() - 1], s, made, ans, costs);
            made.erase(cover);
        }
    }
    return;
}

int main() {
    set<string> made;
    string s;
    cin >> s;
    int n = s.length();
    vector<int> costs(n);
    for (int &cost: costs) {
        cin >> cost;
    }
    int ans = costs[0] * 2;
    backtrack(0, 0, s, made, ans, costs);
    cout << ans << endl;
    return 0;
}