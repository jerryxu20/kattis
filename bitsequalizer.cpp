#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int tcase) {
    string s, t;
    cin >> s >> t;
    int a = count(all(s), '0');
    int b = count(all(s), '?');
    int c = count(all(t), '0');
    if (a + b < c) {
        cout << "Case " << tcase << ": -1\n";
        return 0;
    }    
    int need = max(0, c - a);
    int ans = b;
    for (int i = 0; i < sz(s); i++) {
        if (need == 0) break;
        if (s[i] != '?') continue;
        if (t[i] == '0') {
            need--;
            s[i] = '0';
        }
    }
    for (int i = 0; i < sz(s); i++) {
        if (need == 0) break;
        if (s[i] != '?') continue;
        s[i] = '0';
        need--;
    }
    // now we might have too many 0's
    for (int i = 0; i < sz(s); i++) {
        if (a <= c) break;
        if (s[i] == '0' && t[i] == '1') {
            s[i] = '1';
            a--;
            ans++;
        }
    }
    for (int i = 0; i < sz(s); i++) {
        if (a <= c) break;
        if (s[i] == '0') {
            s[i] = '1';
            a--;
            ans++;
        }
    }
    // not enough 1's
    a = count(all(s), '1');
    b = count(all(t), '1');
    for (int i = 0; i < sz(s); i++) {
        assert(a <= b);
        if (a == b) break;
        if (s[i] == '?') {
            s[i] = '1';
            a++;
        }
    }
    
    int bad = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '?') continue;
        if (s[i] != t[i]) bad++;
    }
    // assert(bad % 2 == 0);
    ans += bad/2;
    cout << "Case " << tcase << ": " << ans << endl;
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}