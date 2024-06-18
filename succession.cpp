#include <bits/stdc++.h>
using namespace std;

map<string, double> amount;
map<string, vector<string>> parents;
double f(string &s) {
    if (amount.count(s)) return amount[s];
    if (!parents.count(s)) return amount[s];

    for (auto &p: parents[s]) {
        amount[s] += f(p);
    }
    amount[s] /= 2;
    return amount[s];
}


int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    amount[s] = 1;
    while(n--) {
        string a, b, c;
        cin >> a >> b >> c;
        parents[a] = {b, c};
    }

    string ans = "";
    while(m--) {
        string a; cin >> a;
        if (f(a) > f(ans)) ans = a;
    }

    cout << ans << endl;
}