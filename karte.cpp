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
    cin >> s;
    map<char, set<int>> suits;
    for (int i = 0; i + 2 < sz(s); i+=3) {
        char suit = s[i];
        int num = stoi(s.substr(i + 1, i + 3));
        if (suits[suit].count(num)) {
            cout << "GRESKA" << endl;
            return 0;
        }
        suits[suit].insert(num);
    }
    cout << 13 - sz(suits['P']) << " " << 13 - sz(suits['K']) << " " << 13 - sz(suits['H']) << " " << 13-sz(suits['T']) << endl;
    return 0;
}