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
    // ATGC
    map<char, char> mp = {
        {'A', 'D'},
        {'T', 'C'},
        {'G', 'B'},
        {'C', 'A'},
    };
    map<char, char> unmap = {
        {'D', 'A'},
        {'C', 'T'},
        {'B', 'G'},
        {'A', 'C'},
    };
    string s;
    cin >> s;
    for (auto &c: s) {
        c = mp[c];
    }
    int n = sz(s);
    map<char, vi> psum;
    psum['A'] = vector<int>(n + 1);
    psum['B'] = vector<int>(n + 1);
    psum['C'] = vector<int>(n + 1);
    psum['D'] = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
        psum['A'][i] += psum['A'][i - 1];
        psum['B'][i] += psum['B'][i - 1];
        psum['C'][i] += psum['C'][i - 1];
        psum['D'][i] += psum['D'][i - 1];
        psum[s[i - 1]][i] += 1;
    }
    int q, a, b;
    cin >> q;
    while(q--) {
        cin >> a >> b;
        vector<pair<int, char>> ans;
        for (char c = 'A'; c <= 'D'; c++) {
            int cnt = psum[c][b] - psum[c][a - 1];
            ans.pb({cnt, c});
        }
        sort(all(ans), greater<pair<int, char>>());
        for (auto &[cnt, a]: ans) {
            cout << unmap[a];
        }
        cout << endl;
    }
    return 0;
}