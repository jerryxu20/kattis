#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

const int MAXN = 5e5;

map<string, int> ID;
string name[MAXN];
int N = 0;

set<int> clause[MAXN];
vector<int> relevant[MAXN];
int then[MAXN];
int added[MAXN];

int id(string &s) {
    if (ID.count(s)) return ID[s];
    name[N] = s;
    ID[s] = N++;
    return ID[s];
}

int add(int x) {
    if (added[x]) return 0;

    added[x] = 1;
    int ans = 1;
    for (int i: relevant[x]) {
        clause[i].erase(x);
        if (sz(clause[i]) == 0) ans += add(then[i]);
    }
    return ans;
}

int main() {
    int c; cin >> c;
    int n = 0;

    string s;
    getline(cin, s);

    vector<int> forced;
    while(c--) {
        cin >> s;

        if (s != "if") {
            forced.push_back(id(s));
            continue;
        }

        vector<int> items;
        int type = 0;
        while(s != "then") {
            cin >> s;
            items.push_back(id(s));
            cin >> s;
            if (s == "and") type = 1;
        }
        cin >> s;
        items.push_back(id(s));

        if (type == 1) {
            then[n] = items.back();
            items.pop_back();

            clause[n] = set(items.begin(), items.end());
            for (auto &x: items) {
                relevant[x].push_back(n);
            }
            n++;
        } else {
            int q = items.back();
            items.pop_back();
            
            for (auto &x: items) {
                relevant[x].push_back(n);
                clause[n].insert(x);
                then[n] = q;

                n++;
            }
        }
    }

    int ans = 0;
    for (int &x: forced) {
        ans += add(x);
    }

    cout << ans << endl;
}