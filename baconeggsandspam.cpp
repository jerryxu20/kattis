#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair

vector<string> split(string &s) {
    s.pb(' ');
    string cur = "";
    vector<string> ans;
    for (auto &c: s) {
        if (c == ' ') {
            if (sz(cur) > 0) {
                ans.pb(cur);
                cur = "";
            }
            continue;
        }
        cur += c;
    }
    return ans;
    
}

int solve() {
    int n;
    map<string, set<string>> mp;
    string s, name;
    while (cin >> n) {
        if (n == 0) break;
        mp.clear();
        while(n--) {
            cin >> name;
            getline(cin, s);
            vector<string> items = split(s);
            for (auto &item: items) {
                mp[item].insert(name);
            }
        }
        for (auto &[item, names]: mp) {
            cout << item << " ";
            for (auto &title: names) {
                cout << title << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

int main() {
    int tcase = 1;
    // cin >> tcase;
    for (int i = 1; i <= tcase; i++) {
        solve();
    }
    return 0;
}