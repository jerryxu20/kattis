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
    string s;
    while(cin >> s) {
        string cur = "";
        s += ' ';
        for (auto &c: s) {
            if (sz(cur) == 10) {
                cout << cur << " " << stoll(cur, nullptr, 16) << endl;
                cur = "";
            }
            if (sz(cur) == 0 && c == '0') {
                cur += c;
                continue;
            }
            if (sz(cur) == 1 && (c == 'x' || c == 'X')) {
                cur += c;
                continue;
            }
            if (isdigit(c) && sz(cur) >= 2) {
                cur += c;
                continue;
            } 
            char t = tolower(c);
            if (sz(cur) >= 2 && t <= 'f' && t >= 'a') {
                cur += c;
                continue;
            } 
            // no way to extend it
            if (sz(cur) > 2) {
                cout << cur << " " << stoll(cur, nullptr, 16) << endl;
            }
            cur = "";

        }
    }
    return 0;
}