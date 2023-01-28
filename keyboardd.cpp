#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    string expected, actual;
    getline(cin, expected);
    getline(cin, actual);
    map<char, int> freq1;
    map<char, int> freq2;
    for (auto &c: actual) {
        freq1[c]++;
    }
    for (auto &c: expected) {
        freq2[c]++;
    }
    for (auto [key, value]: freq1) {
        if (value != freq2[key]) {
            cout << key;
        }
    }
    cout << endl;
}