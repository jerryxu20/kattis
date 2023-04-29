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
    int n;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        bool good = true;
        string stack;
        for (char &c: s) {
            if (c == '$' || c == '|' || c == '*') stack += c;
            else if (c == 't') {
                if (sz(stack) && stack.back() == '|') stack.pop_back();
                else good = false;
            } else if (c == 'b') {
                if (sz(stack) && stack.back() == '$') stack.pop_back();
                else good = false;
            } else if (c == 'j') {
                if (sz(stack) &&stack.back() == '*') stack.pop_back();
                else good = false;
            }
            if (!good) break;
        }
        if (good && sz(stack) == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}