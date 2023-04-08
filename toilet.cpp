#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int first(string s) {
    int ans = 0;
    for (int i = 1; i < sz(s); i++) {
        if (s[i] != s[i - 1]) ans++;
        if (s[i] != 'U') ans++;
        s[i] = 'U';
    }
    return ans;
}

int second(string s) {
    int ans = 0;
    for (int i = 1; i < sz(s); i++) {
        if (s[i] != s[i - 1]) ans++;
        if (s[i] != 'D') ans++;
        s[i] = 'D';
    }
    return ans;
}

int third(string s) {
    int ans = 0;
    for (int i = 1; i < sz(s); i++) {
        if (s[i] != s[i - 1]) ans++;
    }
    return ans;
}

int solve(int tcase) {
    string s;
    cin >> s;
    cout << first(s) << endl;
    cout << second(s) << endl;
    cout << third(s) << endl;
    return 0;
}

int main() {
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    return 0;
}