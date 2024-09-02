#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int cnt[10];

string minn(const string &a, const string &b) {
    if (sz(a) < sz(b)) return a;
    if (sz(b) < sz(a)) return b;
    
    if (a < b) return a;
    return b;
}

int main() {
    string s; cin >> s;

    for (char &c: s) {
        cnt[c - '0']++;
    }

    string ans(1001, '1');


    for (int i = 1; i < 10; i++) {
        ans = minn(ans, string(cnt[i] + 1, i + '0'));
    }

    for (int i = 1; i < 10; i++) {
        if (cnt[i]) {
            string cand;
            cand += i + '0';
            cand += string(cnt[0] + 1, '0');
            
            ans = minn(ans, cand);
        }
    }

    cout << ans << endl;
}