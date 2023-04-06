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

set<char> vowels({'A', 'E', 'I', 'O', 'U'});

ll solve(string &s, int idx, bool L) {
    if (idx == sz(s)) {
        if (L) return 1;
        return 0;
    }
    int v = 0;
    int c = 0;
    int vf = 0;
    int cf = 0;
    ll ans = 0;
    for (int i = max(0, idx - 2); i <= idx; i++) {
        v += vowels.count(s[i]);
        c += (!vowels.count(s[i]) && s[i] != '_');
    }
    if (v >= 3 || c >= 3) return 0;
    if (s[idx] != '_') return solve(s, idx + 1, L);
    // consider puttting vowel

    if (v < 2) {
        s[idx] = 'A';
        ans += 5 * solve(s, idx + 1, L);
        s[idx] = '_';
    }
    if (c < 2) {
        s[idx] = 'T';
        ans += 20 * solve(s, idx + 1, L);
        ans += solve(s, idx + 1, true);
        s[idx] = '_';
    }

    return ans;
    //consider putting a constanent
}

int main() {
    // no three sequential vowels
    // no three sequential constants
    // contain L
    string s;
    cin >> s;
    bool L = count(all(s), 'L');
    cout << solve(s, 0, L) << endl;
    return 0;
}