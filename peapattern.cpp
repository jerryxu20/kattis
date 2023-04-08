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

string peapattern(string &s) {
    map<int, int> freq;
    string ans = "";
    for (char &c: s) {
        freq[c - '0']++;
    }
    for (auto &[letter, cnt]: freq) {
        ans += to_string(cnt);
        ans += to_string(letter);
    }

    return ans;
}

int main() {
    string n, m;
    cin >> n >> m;
    if (n == m) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= 100; i++) {
        n = peapattern(n);
        if (n == m) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "Does not appear" << endl;
    return 0;
}