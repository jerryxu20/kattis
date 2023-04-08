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

int solve(int tcase) {
    string s;
    while(cin >> s) {
        getline(cin, s);
        s += ' ';
        string cur = "";
        map<string, int> domain;
        for (char c: s) {
            if (c == ' ') {
                if (cur == "") continue;
                // cout << "added " << cur << endl; 
                domain[cur];
                cur = "";
            } else {
                cur += c;
            }
        }
        cin >> s;
        getline(cin, s);
        s += ' ';
        cur = "";
        map<string, int> codomain;
        for (char c: s) {
            if (c == ' ') {
                if (cur == "") continue;
                // cout << "added " << cur << endl; 
                codomain[cur];
                cur = "";
            } else {
                cur += c;
            }
        }
        int n;
        cin >> n;
        vector<pair<string, string>> items(n);
        for (auto &[a, b]: items) {
            cin >> a >> s >> b;
            domain[a]++;
            codomain[b]++;
        }
        bool onto = true;
        bool onetoone = true;
        for (auto &[a, b]: codomain) {
            if (b == 0) onto = false;
            if (b > 1) onetoone = false; 
        }
        bool function = true;
        for (auto &[a, b]: domain) {
            if (b > 1) function = false;
        }
        if (!function) {
            cout << "not a function\n";
        } else if (onto && onetoone) {
            cout << "bijective\n";
        } else if (onto) {
            cout << "surjective\n";
        } else if (onetoone) {
            cout << "injective\n";
        } else {
            cout << "neither injective nor surjective\n";
        }
    }
    
    tcase++;
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
    testcase++;
    return 0;
}